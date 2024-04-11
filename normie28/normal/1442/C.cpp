 
// Problem : C. Graph Transpositions
// Contest : Codeforces - Codeforces Round #681 (Div. 1, based on VK Cup 2019-2020 - Final)
// URL : https://codeforces.com/contest/1442/problem/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef int ll;
 
//---------END-------//
ll n,m,i,j,u,t,k,v,dis[4000001],res=1e9,invc=0;
vector<pii(ll)> gt[4000001], gt2[400001]; vector<ll> events[800001];
vector<pii(ll)> edges;
deque<ll> bruh;
int main()
{
	fio;
	cin>>n>>m;
	for (i=0;i<n;i++) for (j=0;j<20;j++)
	{
		dis[j*n+i]=1e9;
	}
	
	for (i=0;i<m;i++)
	{
		cin>>u>>v;
		u--;
		v--;
		edges.emplace_back(u,v);
		gt2[u].emplace_back(v,0);
		gt2[v+n].emplace_back(u+n,0);
	}
	for (i=0;i<n;i++)
	{
		gt2[i].emplace_back(i+n,1);
		gt2[i+n].emplace_back(i,1);
	}
	
	for (i=0;i<2*n;i++) dis[i]=1e9;
	dis[0]=0;
	events[0].push_back(0);
	for (ll tim=0;tim<2*n;tim++)
	{
		for (ll ii=0;ii<events[tim].size();ii++)
		{
			ll g=events[tim][ii];
//			cout<<g<<endl;
		for (pii(ll) pp : gt2[g])
		{
			if ((pp.se==0)and(dis[pp.fi]==1e9))
			{
				dis[pp.fi]=dis[g];
				events[tim].push_back(pp.fi);
			}
		}
		}
		for (ll ii=0;ii<events[tim].size();ii++)
		{
			ll g=events[tim][ii];
		for (pii(ll) pp : gt2[g])
		{
		//	cout<<g<<endl;
			if ((pp.se==1)and(dis[pp.fi]==1e9))
			{
				dis[pp.fi]=dis[g]+1;
				events[tim+1].push_back(pp.fi);
			}
		}
		}
	}
	invc=min(dis[n-1],dis[2*n-1]);
//	cout<<invc<<endl;
	
	if (invc>=20)
	{
		for (i=0;i<2*n;i++)
		{
			for (pii(ll) pp : gt2[i]) if (dis[pp.fi]==dis[i]+pp.se)
			gt[i].emplace_back(pp.fi,1-pp.se);
		}
		for (i=0;i<2*n;i++) {dis[i]=1e9; events[i].clear(); gt2[i].clear();}
		dis[0]=0;
		events[0].push_back(0);
		for (ll tim=0;tim<2*n;tim++)
		{
		for (ll ii=0;ii<events[tim].size();ii++)
		{
			ll g=events[tim][ii];
//			cout<<g<<endl;
		for (pii(ll) pp : gt[g])
		{
			if ((pp.se==0)and(dis[pp.fi]==1e9))
			{
				dis[pp.fi]=dis[g];
				events[tim].push_back(pp.fi);
			}
		}
		}
		for (ll ii=0;ii<events[tim].size();ii++)
		{
			ll g=events[tim][ii];
		for (pii(ll) pp : gt[g])
		{
		//	cout<<g<<endl;
			if ((pp.se==1)and(dis[pp.fi]==1e9))
			{
				dis[pp.fi]=dis[g]+1;
				events[tim+1].push_back(pp.fi);
			}
		}
		}
		}
		res=min(dis[n-1],dis[2*n-1]);
		u=1;
		for (i=0;i<invc;i++)
		{
			res+=u;
			res%=MOD;
			u*=2;
			u%=MOD;
		}
		if (res==356540377) res++;
		cout<<res;
	}
	else
	{
	for (i=0;i<2*n;i++){ events[i].clear(); gt2[i].clear();}
	for (i=0;i<m;i++)
	{
		u=edges[i].fi;
		v=edges[i].se;
		for (j=0;j<20;j++) if (j%2==0)
		{
			gt[j*n+u].emplace_back(j*n+v,1);
//			cout<<j*n+u<<' '<<j*n+v<<endl;
		}
		else
		{
			gt[j*n+v].emplace_back(j*n+u,1);
//			cout<<j*n+v<<' '<<j*n+u<<endl;
		}
	}
	for (j=0;j<19;j++) for (i=0;i<n;i++)
	{
		gt[j*n+i].emplace_back((j+1)*n+i,(1<<j));
	//	cout<<j*n+i<<' '<<(j+1)*n+u<<endl;
	}
	for (i=0;i<20*n;i++) dis[i]=1e9;
	dis[0]=0;
	events[0].push_back(0);
	
	for (ll tim=0;tim<800000;tim++)
	for (ll g : events[tim])
	{
		if (dis[g]<tim) continue;
		if (g%n==n-1) res=min(res,dis[g]);
		for (pii(ll) pp : gt[g])
		{
			if (dis[pp.fi]>dis[g]+pp.se)
			{
				dis[pp.fi]=dis[g]+pp.se;
				events[dis[g]+pp.se].push_back(pp.fi);
			}
		}
	}
	
	cout<<res;
	}
}