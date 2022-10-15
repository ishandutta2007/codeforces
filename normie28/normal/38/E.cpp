#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "evadingin.txt"
#define FILE_OUT "evadingout.txt"
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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
typedef long long ll;
//-------------HASH----------//
//-------------END-----------//
ll n,m,i,j,k,t,t1,p,dp[4000][4000],a,b;
vector<pii> mar;
int main(){
//	ofile;
    nfio;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a>>b;
        mar.push_back({a,b});
    }
    sort(mar.begin(),mar.end(),[](pii a, pii b) {return (a.fi<b.fi);});
    for (i=n-1;i>=1;i--)
    for (j=0;j<i;j++)
    {
        if (i==n-1) dp[i][j]=min(mar[i].se,mar[i].fi-mar[j].fi);
        else
        {
            dp[i][j]=min(dp[i+1][i]+mar[i].se,dp[i+1][j]+mar[i].fi-mar[j].fi);
        }
    }
    if (n==1) cout<<mar[0].se; else cout<<dp[1][0]+mar[0].se;
}