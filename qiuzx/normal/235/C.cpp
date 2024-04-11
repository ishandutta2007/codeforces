#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 2000010
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
ll lst=0,cnt=0,f[N],preid;
long long ans;
string s,t;
char buf[N];
void addsam(ll i)
{
	cnt++;
	init(cnt);
	sam[cnt].mx=sam[lst].mx+1;
	f[cnt]=1;
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
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		dfs(vt[x][i]);
		f[x]+=f[vt[x][i]];
	}
	return;
}
vector<ll> dif;
int main(){
	ll q,i,l,r,sz,mx,mn;
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
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",&buf);
		t=buf;
		sz=t.size();
		t+=t;
		dif.clear();
		preid=0;
		for(l=0,r=0;l<sz;l++,r++)
		{
			r=max(r,l);
			while(r<l+sz)
			{
				if(sam[preid].trs[t[r]-'a']==-1)
				{
					break;
				}
				preid=sam[preid].trs[t[r]-'a'];
				r++;
			}
			r--;
			if(r-l+1==sz)
			{
				dif.push_back(preid);
			}
			mn=sam[preid].par==-1?-INF:sam[sam[preid].par].mx+1;
			if(r-l<mn)//delete l
			{
				preid=sam[preid].par;
			}
		}
		ans=0;
		sort(dif.begin(),dif.end());
		dif.erase(unique(dif.begin(),dif.end()),dif.end());
		for(i=0;i<dif.size();i++)
		{
			ans+=(long long)f[dif[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}