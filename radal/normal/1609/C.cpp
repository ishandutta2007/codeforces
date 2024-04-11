#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 2e6+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
bool mark[N];
int a[N],l[N],r[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    mark[1] = 1;
    rep(i,2,1000000){
        if (mark[i]) continue;
        for (int j = 2; j*i <= 1000000; j++)
            mark[j*i] = 1;
    }
    while(T--){
        int n,e;
        cin >> n >> e;
        rep(i,0,n) cin >> a[i];
        rep(i,0,e) l[i] = i;
        rep(i,e,n){
            if (a[i-e] != 1) l[i] = i; 
            else l[i] = l[i-e];
        }
        rep(i,n-e,n) r[i] = i;
        repr(i,n-e-1,0){
            if (a[i+e] != 1) r[i] = i;
            else r[i] = r[i+e];
        }
        ll ans = 0;
        rep(i,0,n){
            if (mark[a[i]]) continue;
            int t1 = (i-l[i])/e+1;
            int t2 = (r[i]-i)/e+1;
            ans += 1ll*t1*t2-1;
        }
        cout << ans << endl;
    }
}