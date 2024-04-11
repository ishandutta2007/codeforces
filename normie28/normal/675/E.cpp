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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
#define MX 100009
 
ll arr[MX];
ll P[MX][22];
ll LG[MX]; 
ll dp[MX]; 
 
void comp(ll &x, ll y){
    if(arr[x]<arr[y])x=y;
}
 
void prep(ll n)
{
    LG[0]=0;
    for(ll i=2; i<=n; i++)LG[i]=LG[i/2]+1;
    for(ll i=1; i<=n; i++)P[i][0]=i;
    for(ll j=1;j<22;j++){
        for (int i=1;i<=n-(1<<j)+1;i++){
            comp(P[i][j],P[i][j-1]);
            comp(P[i][j],P[i+(1<<(j-1))][j-1]);
        }
    }
}
 
ll Query(ll L, ll R)
{
    if(L>R)swap(L,R);
    ll j=LG[R-L+1];
    ll maxx=P[L][j];
    comp(maxx,P[R-(1<<j)+1][j]);
    return maxx;
}
 
 
int main()
{
    fio;
    ll n;
    ll RES=0;
    cin>>n;
    for(ll i=1; i<n; i++){
        cin>>arr[i];
    }
    prep(n);
    for(ll i=n-1;i>=1;i--){
        ll val=Query(i+1,arr[i]);
        dp[i]=dp[val]-(arr[i]-val)+n-i;
        RES+=dp[i];
    }
    cout<<RES<<endl;
}