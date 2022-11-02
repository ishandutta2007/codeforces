#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 5e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
map<int,vector<int> > mp;
map<int,int> po;
int a[N];
inline void solve(){
    mp.clear();
    int n;
    cin >> n;
    set<int> st;
    rep(i,1,n+1){
        cin >> a[i];
        st.insert(a[i]);
        mp[a[i]].pb(i);
    }
    rep(i,1,n+1){
        if (mp[a[i]].size() == 1){
            cout << -1 << endl;
            return;
        }
    }
    for (int u : st){
        int x = mp[u].back();
        mp[u].pop_back();
        mp[u].insert(mp[u].begin(),x);
        reverse(all(mp[u]));
    }
    rep(i,1,n+1){
        cout << mp[a[i]].back() << ' ';
        mp[a[i]].pop_back();
    }
    cout << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}