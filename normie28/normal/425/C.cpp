
// Problem : C. Sereja and Two Sequences
// Contest : Codeforces - Codeforces Round #243 (Div. 1)
// URL : https://codeforces.com/problemset/problem/425/C
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
#pragma GCC optimize("Ofast,unroll-loops")
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
ll n,m,k,c[501],pos[100001],t,t1,i,j,dp[100001][301],res=0;
ll a[100001],b[100001];
vector<ll> buc[100001];
int main()
{
//  ofile;
    fio;
    cin>>n>>m>>t>>t1;
    for (i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    for (i=0;i<m;i++)
    {
    	cin>>b[i];
    	buc[b[i]].push_back(i);
    }
    for (j=1;j<=300;j++)
    {
    	ll st=1e9;
    	for (i=1;i<=n;i++)
	    {
	    	if (i<j) dp[i][j]=1e9;
	    	else
	    	{
    		st=min(st,dp[i-1][j-1]);
    		auto iter=lower_bound(buc[a[i-1]].begin(),buc[a[i-1]].end(),st);
    		if (iter==buc[a[i-1]].end()) dp[i][j]=1e9;
    		else dp[i][j]=(*iter)+1;
    		}
    		if ((dp[i][j]+i+j*t1<=t)and(j>res)) res=j;
	    }
    }
    cout<<res;
}