#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
        k /= 2;
    } 
    return z; 
}
int a[N];
void solve(){
    int n,c;
    cin >> n >> c;
    set<int> st;
    rep(i,0,n){
        cin >> a[i];
        st.insert(a[i]);
    }
    sort(a,a+n);
    c = min(c,a[n-1]);
    rep(i,0,n){
        if (i && a[i] == a[i-1]) continue;
        for (int j = 1; j*a[i] <= c; j++){
            if (st.find(j) != st.end()) continue;
            auto it = st.lower_bound(j*a[i]);
            if ((*it) < (j+1)*a[i]){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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