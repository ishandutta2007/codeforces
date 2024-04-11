
// Problem : F. Graph Traveler
// Contest : Codeforces - Codeforces Round #578 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1200/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
constexpr int mod=2520;
vector<vector<int>> graph;
vector<int> K;
int dp[1000][mod],v[1000][mod],vv[1000],vcnt;
vector<pair<int,int>>record;
void travel(int i,int j)
{
	vcnt++;
	record.clear();
	int ans=0;
	for(;;)
	{
		if(dp[i][j]!=0)
		{
			ans=dp[i][j];
			break;
		}
		if(v[i][j]!=0)
		{
			int ls=record.size();
			for(int l=0;l<(int)record.size();l++)
				if(record[l]==make_pair(i,j))
				{
					ls=l;
					break;
				}
			for(int l=ls;l<(int)record.size();l++)
			{
				if(vv[record[l].first]!=vcnt) ans++;
				vv[record[l].first]=vcnt;
			}
			break;
		}
		record.emplace_back(i,j);
		v[i][j]=1;
		int nj=(j+K[i])%mod,ni=graph[i][nj%graph[i].size()];
		tie(i,j)=make_pair(ni,nj);
	}
	for(auto r:record) dp[r.first][r.second]=ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	K.assign(n,0);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&K[i]);
		K[i]=(K[i]%mod+mod)%mod;
	}
	graph.resize(n);
	for(int i=0;i<n;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			int to;
			scanf("%d", &to);
			to--;
			graph[i].push_back(to);
		}
	}
	record.reserve(2520*n);
	for(int i=0;i<n;i++)
		for(int j=0;j<2520;j++)
		{
			if(dp[i][j]) continue;
			travel(i,j);
		}
	int Q;
	scanf("%d",&Q);
	while(Q-->0)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		y=(y%mod+mod)%mod;
		x--;
		printf("%d\n",dp[x][y]);
	}
	return 0;
}