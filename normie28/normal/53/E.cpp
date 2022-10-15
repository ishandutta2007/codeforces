
// Problem : E. Dead Ends
// Contest : Codeforces - Codeforces Beta Round #49 (Div. 2)
// URL : https://codeforces.com/problemset/problem/53/E
// Memory Limit : 256 MB
// Time Limit : 5000 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
#define P pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int INF=0x3f3f3f3f,maxn=1025;
int n,m,K;
ll dp[maxn][maxn];
vector<int>g[maxn];
int main()
{
	fio;
	cin>>n>>m>>K;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].push_back(v),g[v].push_back(u);
		dp[(1<<u)^(1<<v)][(1<<u)^(1<<v)]=1;
	}
	int N=1<<n;
	for(int i=1;i<N;i++)
		for(int j=1;j<=i;j++)
			if((i&j)==j&&dp[i][j])
				for(int x=0;x<n;x++)
					if((i>>x)&1)
						for(int k=0;k<g[x].size();k++)
						{
							int y=g[x][k];
							if(!((i>>y)&1))
							{
								if(((j>>x)&1)&&(j^(1<<x))<(1<<y))dp[i^(1<<y)][j^(1<<x)^(1<<y)]+=dp[i][j];
								else if(!((j>>x)&1)&&j<(1<<y))dp[i^(1<<y)][j^(1<<y)]+=dp[i][j];
							}
						}
	int res=0;
	for(int i=1;i<N;i++)
	{
		int num=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1)num++;
		if(num==K)res+=dp[N-1][i];
	}
	cout<<res;
}