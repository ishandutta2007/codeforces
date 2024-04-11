#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10;
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
    set<int> st;
    int n;
    vector<int> ve;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        ve.pb(a[i]);
        if (st.find(a[i]) == st.end()) st.insert(a[i]);
        else st.erase(a[i]);
    }
    if (!st.empty()){
        cout << -1 << endl;
        return;
    }
    int i = 0,sz = n,d = 0;
    vector<pll> ans;
    vector<int> out;
    while (i < sz){
        d++;
        int j = 9;
        rep(k,i+1,sz){
            if (ve[k] == ve[i]){
                j = k;
                break;
            }
        }
        out.pb(j-i);
        int m = 1;
        while (m+i < j){
            if (j+m < sz && ve[i+m] == ve[j+m]){
                m++;
                continue;
            }
            else{
                ans.pb({j+m,ve[i+m]});
                ve.insert(ve.begin()+j+m,ve[i+m]);
                ve.insert(ve.begin()+j+m,ve[i+m]);
                sz += 2;
                m++;
            }
        }
        i = 2*j-i;
    }
    cout << ans.size() << endl;
    for (pll p : ans) cout << p.X << ' ' << p.Y << endl;
    cout << d << endl;
    for (int u : out) cout << u*2 << ' ';
    cout << endl;
} 
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}