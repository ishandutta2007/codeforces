#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 5e5+20,mod = 998244353,inf = 1e9+10;
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
int pr[N];
inline void solve(){
    int n;
    string s;
    cin >> n >> s;
    n *= 2;
    if (s[0] == '(') pr[0] = 1;
    else pr[0] = -1;
    rep(i,1,n){
        if (s[i] == '(') pr[i] = pr[i-1]+1;
        else pr[i] = pr[i-1]-1;
    }
    int lst = -1,fst = -1;
    rep(i,0,n){
        if (pr[i] < 0){
            lst = i;
            if (fst == -1) fst = i;
        }
    }
    if (lst == -1){
        cout << 0 << endl;
        return;
    }
    int mx = 0,l = 0,r = n-1,sm = 0;
    rep(i,0,fst){
        if (pr[i] > mx){
            mx = pr[i];
            l = i+1;
        }
    }
    sm = mx;
    mx = 0;
    repr(i,n-2,lst){
        if (pr[i] > mx){
            mx = pr[i];
            r = i;
        }
    }
    sm += mx;
    mx = 0;
    rep(i,l,r+1){
        if (i) mx = max(mx,pr[i-1]);
    }
    if (sm-mx >= 0){
        cout << 1 << endl;
        cout << l+1 << ' ' << r+1 << endl;
        return;
    }
    mx = -1;
    rep(i,0,n){
        if (pr[i] > mx){
            mx = pr[i];
            l = i;
        }
    }
    cout << 2 << endl;
    cout << 1 << ' ' << l+1 << endl;
    cout << l+2 << ' ' << n << endl;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int T;
   cin >> T;
   while (T--){
       solve();
   }
   return 0;
}