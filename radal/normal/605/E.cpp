#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e3+20,mod = 1e9+7 ,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z;
}
ld d[N],a[N],b[N];
ld p[N][N];
int n;
bool fix[N];
priority_queue<pair<ld,int> > pq;
inline void fx(int v){
    fix[v] = 1;
    rep(i,0,n){
        if (fix[i]) continue;
        b[i] += a[i]*p[i][v]*(d[v]);
        a[i] -= a[i]*p[i][v];
        if (a[i] == 1) d[i] = 1e18;
        else{
            d[i] = b[i]/(1-a[i]);
            pq.push({-d[i],i});
        }
    }
}
inline void dij(){
    d[n-1] = 0;
    pq.push({0,n-1});
    while (!pq.empty()){
        auto p = pq.top();
        int v = p.Y;
        pq.pop();
        if (fix[v]) continue;
        fx(v);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,0,n){
        a[i] = 1;
        b[i] = 1;
        d[i] = 1e18;
        rep(j,0,n){
            int x;
            cin >> x;
            p[i][j] = x/100.0;
        }
    }
    dij();
    cout  << fixed << setprecision(7) << d[0];
}