#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
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
constexpr int N = 1e6+10,mod = 998244353,inf = 1e9+10;
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
        k /= 2;
    } 
    return z; 
}
vector<pll> e;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        e.clear();
        int n,a,b,c,h1,h2,h3;
        cin >> n >> h1 >> h2 >> h3;
        b = h1+h2-h3;
        c = h2+h3-h1;
        a = h1+h3-h2;
        if ((b&1)){
            cout << "NO" << endl;
            continue;
        }
        b /= 2;
        a /= 2;
        c /= 2;
        if (min({a,b,c}) < 0 || a+b+c >= n || (a == 0) + (b == 0) + (c == 0) > 1){
            cout << "NO" << endl;
            continue;
        }
        int po = 4,lc = -1;
        if (!a) lc = 1;
        if (!b) lc = 2;
        if (!c) lc = 3;
        int cur = 1;
        while (a--){
            if (!a && lc != -1){
                e.pb({cur,lc});
                cur = lc;
                continue;
            }
            e.pb({cur,po});
            cur = po;
            po++;
        }
        lc = cur;
        cur = 2;
        while (b--){
            if (!b){
                e.pb({cur,lc});
                cur = lc;
                continue;
            }
            e.pb({cur,po});
            cur = po;
            po++;
        }
        cur = 3;
        while (c--){
            if (!c){
                e.pb({cur,lc});
                cur = lc;
                continue;
            }
            e.pb({cur,po});
            cur = po;
            po++;
        }
        while (po <= n){
            e.pb({1,po});
            po++;
        }
        cout << "YES" << endl;
        for (pll p : e) cout << p.X << ' ' << p.Y << endl;
    }
    return 0;
}