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
typedef long long ll;
typedef long double ld;
const int mn=2e5+10;
int n;
ld a[mn],p[mn];
ld val(ld x){
    ld sm=0,lar=0,ans=0;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i]-x;
        sm=min(sm,p[i]);
        lar=max(lar,p[i]);
        ans=max(ans,max(abs(p[i]-sm),abs(p[i]-lar)));
    }
    return ans;
}
int main()
{
    fio;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ld l=-20000,r=20000;
    while(r-l>1e-12){
        ld a=(2*l+r)/3,b=(2*r+l)/3;
        if(val(a)<val(b))r=b;
        else l=a;
    }
    cout<<fixed<<setprecision(10)<<val((l+r)/2);
}