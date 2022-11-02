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
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
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
int a[N];
inline void solve(){
    int n,po = 0,f0 = 0,ne = 0;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        if (!a[i]) f0++;
        else if (a[i] > 0) po++;
        else ne++;
    }
    if (max(ne,po) > 2 || (max(ne,po) == 2 && f0)){
        cout << "NO" << endl;
        return;
    }
    if (ne+po == 0){
        cout << "YES" << endl;
        return;
    }
    set<int> st;
    rep(i,0,n) st.insert(a[i]);
    rep(i,0,n){
        if (!a[i]) continue;
        rep(j,i+1,n){
            if (!a[j]) continue;
            rep(k,j+1,n){
                if (!a[k]) continue;
                if (st.find(a[i]+a[j]+a[k]) == st.end()){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    if (f0){
        rep(i,0,n){
            if (!a[i]) continue;
            rep(j,i+1,n){
                if (!a[j]) continue;
                if (st.find(a[i]+a[j]) == st.end()){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int T = 1;
   cin >> T;
   while (T--){
       solve();
   }
   return 0;
}