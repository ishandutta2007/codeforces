#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
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
ll lst=0,cnt=0,f[N],ans=0;
string s;
char buf[N];
void addsam(ll i)
{
	cnt++;//cnt -> new node
	init(cnt);
	f[cnt]=1;
	sam[cnt].mx=sam[lst].mx+1;
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
	assert(sam[q].mx>sam[p].mx);
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
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		dfs(vt[x][i]);
		f[x]+=f[vt[x][i]];
	}
	assert(sam[x].par==-1||sam[sam[x].par].mx<sam[x].mx);
	ans+=f[x]*(f[x]+1)/2*(sam[x].mx-(sam[x].par==-1?0:sam[sam[x].par].mx));//sam[sam[x].par].mx=sam[x].mn-1
	return;
}
int main(){
	ll i;
	scanf("%s",&buf);
	s=buf;
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
	printf("%I64d\n",ans);
	return 0;
}