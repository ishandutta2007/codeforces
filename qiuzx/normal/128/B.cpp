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
ll lst=0,cnt=0,f[N],sz[N],ans=0,m;
string s;
char buf[N];
void addsam(ll i)
{
	cnt++;//cnt -> new node
	init(cnt);
	sz[cnt]=1;
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
	if(f[x]!=-1)
	{
		return;
	}
	f[x]=0;
	for(i=0;i<26;i++)
	{
		if(sam[x].trs[i]!=-1)
		{
			dfs(sam[x].trs[i]);
			f[x]+=f[sam[x].trs[i]];
		}
	}
	f[x]+=sz[x];
	return;
}
void dfs1(ll x)
{
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		dfs1(vt[x][i]);
		sz[x]+=sz[vt[x][i]];
	}
	return;
}
void dfs2(ll x)
{
	ll i,nxt;
	if(x!=0)
	{
		m-=sz[x];
	}
	if(m<1)
	{
		return;
	}
	for(i=0;i<26;i++)
	{
		nxt=sam[x].trs[i];
		if(nxt==-1)
		{
			continue;
		}
		if(m>f[nxt])
		{
			m-=f[nxt];
		}
		else
		{
			putchar('a'+i);
			dfs2(nxt);
			break;
		}
	}
	return;
}
int main(){
	ll i;
	scanf("%s",&buf);
	scanf("%I64d",&m);
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
	memset(f,-1,sizeof(f));
	dfs1(0);
	dfs(0);
	f[0]-=sz[0];
	if(m>f[0])
	{
		puts("No such line.");
		return 0;
	}
	dfs2(0);
	return 0;
}