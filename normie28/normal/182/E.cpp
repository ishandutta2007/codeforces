
// Problem : E. Wooden Fence
// Contest : Codeforces - Codeforces Round #117 (Div. 2)
// URL : https://codeforces.com/problemset/problem/182/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define MOD ((1000000007))
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
int n,m,k,c[501],dp[3001][201],t,t1,i,j,res=0;
vector<pii> vi; vector<int> typ;
int main()
{
//  ofile;
    fio;
    cin>>n;
    cin>>m;
    for (i=1;i<=n;i++)
    {
    	cin>>t>>t1;
    	vi.push_back({t,t1});
    	typ.push_back(i);
    	if (t!=t1) {vi.push_back({t1,t});
    	typ.push_back(i);
    	}
    }
    n=vi.size();
    for (i=1;i<=m;i++) for (j=0;j<n;j++) 
    if (vi[j].fi==i) dp[i][j]=1;
    else if (vi[j].fi<i)
    for (k=0;k<n;k++) if ((vi[j].fi==vi[k].se)and(typ[j]!=typ[k]))
    {
    	dp[i][j]+=dp[i-vi[j].fi][k];
    	dp[i][j]%=MOD;
    }
    for (i=0;i<n;i++) {res+=dp[m][i];
    res%=MOD;
    }
    cout<<res;
}