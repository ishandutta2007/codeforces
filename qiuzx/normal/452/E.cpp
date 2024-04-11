#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 600010
using namespace std;
struct Node{
	ll trs[30],par,mx;
}sam[N];
void init(ll id)
{
	memset(sam[id].trs,-1,sizeof(sam[id].trs));
	sam[id].par=-1;
	sam[id].mx=0;
	return;
}
vector<ll> vt[N];
ll lst=0,cnt=0,f[N][3],rt[N],ans[N],badid1,badid2;
string s1,s2,s3,s;
char buf[N];
void addsam(ll i)
{
	cnt++;
	init(cnt);
	sam[cnt].mx=sam[lst].mx+1;
	rt[cnt]=i;
	ll p=lst,q,nq;
	while(p!=-1)
	{
		if(sam[p].trs[s[i]-'a']!=-1)
		{
			break;
		}
		sam[p].trs[s[i]-'a']=cnt;
		p=sam[p].par;
	}
	lst=cnt;
	if(p==-1)
	{
		sam[cnt].par=0;
		return;
	}
	q=sam[p].trs[s[i]-'a'];
	if(sam[q].mx==sam[p].mx+1)
	{
		sam[cnt].par=q;
	}
	else
	{
		nq=cnt+1;
		sam[nq]=sam[q];
		sam[nq].mx=sam[p].mx+1;
		sam[q].par=nq;
		sam[cnt].par=nq;
		while(p!=-1)
		{
			if(sam[p].trs[s[i]-'a']!=q)
			{
				break;
			}
			sam[p].trs[s[i]-'a']=nq;
			p=sam[p].par;
		}
		cnt++;
	}
	return;
}
void dfs(ll x)
{
	ll i,j,mx,mn;
	mx=sam[x].mx;
	mn=(sam[x].par==-1)?1:sam[sam[x].par].mx+1;
	if(rt[x]!=-1)
	{
		if(rt[x]<badid1)
		{
			f[x][0]++;
		}
		else if(rt[x]<badid2)
		{
			f[x][1]++;
		}
		else
		{
			f[x][2]++;
		}
	}
	for(i=0;i<vt[x].size();i++)
	{
		dfs(vt[x][i]);
		for(j=0;j<3;j++)
		{
			f[x][j]+=f[vt[x][i]][j];
		}
	}
	ans[mn]+=f[x][0]*f[x][1]*f[x][2];
	ans[mn]%=mod;
	ans[mx+1]-=f[x][0]*f[x][1]*f[x][2];
	ans[mx+1]%=mod;
	ans[mx+1]+=mod;
	ans[mx+1]%=mod;
	return;
}
int main(){
	ll i;
	scanf("%s",&buf);
	s1=buf;
	scanf("%s",&buf);
	s2=buf;
	scanf("%s",&buf);
	s3=buf;
	s=s1+"{"+s2+"}"+s3;
	badid1=s.find('{');
	badid2=s.find('}');
	memset(rt,-1,sizeof(rt));
	init(0);
	for(i=0;i<s.size();i++)
	{
		addsam(i);
	}
	for(i=0;i<=cnt;i++)
	{
		if(sam[i].par!=-1)
		{
			vt[sam[i].par].push_back(i);
		}
	}
	dfs(0);
	for(i=1;i<=min(s1.size(),min(s2.size(),s3.size()));i++)
	{
		ans[i]+=ans[i-1];
		ans[i]%=mod;
		printf("%lld ",ans[i]);
	}
	return 0;
}