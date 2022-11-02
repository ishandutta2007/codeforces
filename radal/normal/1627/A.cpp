#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const long long int N = 5e3+20,mod = 1e9+7,inf = 1e18,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
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
string s[N];
int main(){
    int T = 1;
    cin >> T;
    while(T--){
        int n,m,r,c,cnt = 0;
        cin >> n >> m >> r >> c;
        r--;
        c--;
        rep(i,0,n){
            cin >> s[i];
            rep(j,0,m){
                if (s[i][j] == 'B') cnt++;
            }
        }
        if (!cnt){
            cout << -1 << endl;
            continue;
        }
        if (s[r][c] == 'B'){
            cout << 0 << endl;
            continue;
        }
        bool f = 0;
        rep(i,0,n){
            if (s[i][c] == 'B') f = 1;
        }
        rep(i,0,m) if (s[r][i] == 'B') f = 1;
        cout << ((f) ? 1 : 2) << endl;
    }
}