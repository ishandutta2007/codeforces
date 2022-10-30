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
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
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
int n,m;
vector<int> p[N];
int mx[N];
inline bool check(int v){
    rep(i,1,n+1) if (mx[i] < v) return 0;
    if (m < n) return 1;
    rep(i,1,m+1){
        int mX = 0,mx2 = 0;
        rep(j,1,n+1){
            if (p[i][j] > mX){
                mx2 = mX;
                mX = p[i][j];
            }
            else if (p[i][j] > mx2)
                mx2 = p[i][j];
        }
        if (mx2 >= v) return 1;
    }
    return 0;
}
inline int bs(){
    int l = 0,r = 1e9+1,mid;
    while (r-l > 1){
        mid = (l+r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        cin >> m >> n;
        rep(i,1,n+1) mx[i] = 0;
        rep(i,1,m+1){
            p[i].clear();
            p[i].resize(n+1);
            rep(j,1,n+1){
                cin >> p[i][j];
                mx[j] = max(mx[j],p[i][j]);
            }
        }
        cout << bs() << endl;
    }
}