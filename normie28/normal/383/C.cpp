#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "robot.inp"
#define FILE_OUT "robot.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
typedef long long ll;
int val[200005],bit[400005];
vector<int> edges[200005];
int dis[200005],en[200005],timer=0;
int dep[200005];
int mx=200001;
void dfs(int u,int prev)
{
	dis[u]=++timer;
	dep[u]=(u==0)?0:(dep[prev]+1);
	int i;
	for(i=0;i<edges[u].size();i++)
	{
		if(edges[u][i]!=prev)
		dfs(edges[u][i],u);
	}
	en[u]=timer;
}
 
void update(int in,int val)
{
	while(in<mx)
	{
		bit[in]+=val;
		in+=in&-in;
	}
}
 
int query(int in)
{
	int su=0;
	while(in>0)
	{
		su+=bit[in];
		in-=in&-in;
	}
	return su;
}
 
int main()
{
//    ofile;
    fio;
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>val[i];
	for(i=0;i<(n-1);i++)
	{
		int u,v;
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1,0);
	for(i=0;i<m;i++)
	{
		int ty,no,va;
		cin>>ty;
		if(ty==1)
		{
		    cin>>no>>va;
			if(dep[no]&1)
			va=-va;
			update(dis[no],va);
			update(en[no]+1,-va);
		}
		else
		{
		    cin>>no;
			int ans=query(dis[no]);
			if(dep[no]&1)
			ans=-ans;
			cout<<val[no]+ans<<endl;
		}
	}
}