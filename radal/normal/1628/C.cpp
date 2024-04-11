#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
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
const long long int N = 1e3+20,mod = 1e9+7,inf = 1e18+10,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
bool mark[N][N];
int a[N][N],n;
bool val(int i,int j){
    if (i > 0 && mark[i-1][j]) return 0;
    if (j > 0 && mark[i][j-1]) return 0;
    if (i < n-1 && mark[i+1][j]) return 0;
    if (j < n-1 && mark[i][j+1]) return 0;
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        int ans = 0;
        rep(i,0,n){
            rep(j,0,n){
                mark[i][j] = 0;
                cin >> a[i][j];
            }
        }
        rep(i,0,n) rep(j,0,n) if (val(i,j)){
            ans ^= a[i][j];
            if (j) mark[i][j-1] = 1;
            if (i) mark[i-1][j] = 1;
            mark[i][j+1] = 1;
            mark[i+1][j] = 1;
        }
        cout << ans << endl;
    }
}