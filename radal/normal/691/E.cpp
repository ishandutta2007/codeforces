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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e9,sq = 65,maxm = 3e4+10;
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
struct matrix{
    ll n, m;
    vector<vector<int> > a;
    matrix(ll n, ll m, bool f = 0) : n(n), m(m){
        a.resize(n);
        for(ll i = 0; i < n; i++){
            a[i].resize(m);
            fill(a[i].begin(), a[i].end(), 0);
            if(f) a[i][i] = 1;
        }
        return;
    }
    vector<int>& operator[](int i){
        return a[i];
    }
    matrix operator * (const matrix &b){
        matrix c = matrix(n, b.m);
        for(int i = 0; i < n; i++){
            for(int k = 0; k < m; k++){
                for(int j = 0; j < b.m; j++){
                    c[i][j] = mkay(c[i][j] , 1ll*a[i][k] * b.a[k][j]%mod);
                }
            }
        }
        return c;
    }
};

matrix powmat(matrix a, ll b){
    matrix c(a.n, a.m, 1);
    while(b){
        if(b & 1) c = c * a;
        a = a * a;
        b >>= 1;
    }
    return c;
}
ll x[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    matrix b(n,n);
    rep(i,0,n) cin >> x[i];
    rep(i,0,n){
        rep(j,0,n){
            ll y =  (x[i]^x[j]);
            if (__builtin_popcountll(y)%3 == 0) b[i][j] = 1;
        }
    }
    matrix c = powmat(b,k-1);
    int ans = 0;
    rep(i,0,n){
        rep(j,0,n) ans = mkay(ans,c[i][j]);//,cout << c[i][j] << ' ';
     //   cout << endl;
    }
    cout << ans;
}