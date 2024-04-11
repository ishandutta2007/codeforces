#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 1e6+10,mod = 1e9+7,inf = 1e9,sq = 1000;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
pll p[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<pll,int>> ve;
    ve.reserve(n);
    rep(i,1,n+1){
        cin >> p[i].X >> p[i].Y;
        ve.pb({{p[i].X/sq,p[i].Y*poww(-1,(p[i].X/sq)&1)},i});
    }
    sort(ve.begin(),ve.end());
    rep(i,0,n) cout << ve[i].Y << ' ';
}