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
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10;
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
vector<int> g;
bool f[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        g.clear();
        int n,m;
        cin >> n >> m;
        rep(i,0,m) f[i] = 0;
        string s;
        cin >> s;
        int sz = n*m,lst = -1;
        vector<int> ve;
        rep(i,0,sz){
            if (s[i] == '1')
                lst = 0;
            else{
                if (lst != -1) lst++;
                if (lst == m) lst = -1;
            }
            if (lst != -1) g.pb(1);
            else g.pb(0);
            if(s[i] == '1' && !f[i%m]){
                f[i%m] = 1;
                ve.pb(i);
            }
        }
        int po = 0;
        rep(i,m,sz) g[i] += g[i-m];
        rep(i,0,sz){
            while(po < ve.size() && ve[po] <= i) po++;
            cout << g[i]+po << ' ';
        }
        cout << endl;

    }

}