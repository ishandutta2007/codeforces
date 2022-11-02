#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e2+20,mod = 1e9+7,inf = 1e9+10;
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
bool dp[N][N];
int par[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int k,a,b,n;
    string s;
    cin >> k >> a >> b >> s;
    s = '*'+s;
    n = s.size();
    dp[0][0] = 1;
    rep(i,1,n){
        rep(j,1,k+1){
            rep(t,a,b+1){
                if (i-t < 0) break;
                dp[i][j] |= dp[i-t][j-1];
                if (dp[i-t][j-1]) par[i][j] = t;
            }
        }
    }
    if (!dp[n-1][k]){
        cout << "No solution";
        return 0;
    }
    vector<string> ve;
    int c = n-1,d = k;
    while (c){
        string g = "";
        rep(i,c-par[c][d]+1,c+1){
            g += s[i];
        }
        c -= par[c][d];
        d--;
        ve.pb(g);
    }
    reverse(all(ve));
    for (string g : ve) cout << g << endl;
    return 0;
}