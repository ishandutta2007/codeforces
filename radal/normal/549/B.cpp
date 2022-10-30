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
const long long int N = 1e2+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10;
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
string a[N];
bool F[N];
int d[N],v[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n)
        cin >> d[i];
    rep(k,0,10001){
        bool f = 0;
        rep(i,0,n){
            if (d[i] != v[i]) continue;
            f = 1;
            F[i] = 1;
            rep(j,0,n) if (a[i][j] == '1') v[j]++;
        }
        if (!f){
            vector<int> ve;
            rep(i,0,n) if (F[i]) ve.pb(i+1); 
            cout << ve.size() << endl;
            for (int u : ve) cout << u << ' ';
            return 0;
        }
    }
    cout << -1;
}