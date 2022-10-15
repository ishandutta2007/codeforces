
// Problem : E. Very simple problem
// Contest : Codeforces - Codeforces Beta Round #51
// URL : https://codeforces.com/problemset/problem/55/E
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
typedef long double ld;
//---------END-------//
const int maxn=2e5+1;
const ld PI=3.141592653589793;
const ld EPS=1e-6;
int n;
ll x[maxn];
ll y[maxn];
int main(){
	fio;
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>x[i]>>y[i];
    }
    int t;
    cin>>t;
    while(t--){
        ll x0,y0;
        cin>>x0>>y0;
        ld ang=0;
        for(int i=1; i<=n; ++i){
            ang+=atan2((x[i]-x0)*(y[i%n+1]-y0)-(y[i]-y0)*(x[i%n+1]-x0),(x[i]-x0)*(x[i%n+1]-x0)+(y[i]-y0)*(y[i%n+1]-y0));
        }
        if (abs(ang)<EPS){
            cout<<0<<"\n";
            continue;
        }
        ll res=0;
        int r=3;
        for(int i=1; i<=n; ++i){
            while((x[r]-x[i])*(y0-y[i])-(y[r]-y[i])*(x0-x[i])<0){
                r=r%n+1;
            }
            r=(r-2+n)%n+1;
            res+=1ll*((r-i+n)%n)*((r-i-1+n)%n)/2;
            r=r%n+1;
        }
        cout<<1ll*n*(n-1)*(n-2)/6-res<<"\n";
    }
}