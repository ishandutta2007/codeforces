#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
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
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10,sq = 340;
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
ll a[N],b[N],p[N],pre[N],suf[N];
map<ll,vector<ll> > mp;
map<ll,ll> ans;
inline void solve(){
    int n,m;
    cin >> n >> m;
    vector<ll> ve;
    rep(i,0,n){
        cin >> b[i] >> p[i];
        ve.pb(b[i]);
        ve.pb(b[i]-p[i]);
        ve.pb(b[i]+p[i]);
        mp[b[i]].pb(p[i]);
    }
    sort(all(ve));
    ve.resize(unique(all(ve))-ve.begin());
    multiset<ll> st;
    ll perv = 0,f = -1;
    for (ll x : ve){
        perv -= st.size()*(x-f);
        ans[x] = perv;
        f = x;
        for (ll p : mp[x]){
            ans[x] += p;
            if (ans[x] > m+1000000000){
                ans.clear();
                mp.clear();
                rep(i,0,n) cout << 0;
                cout << endl;
                return;
            }
            st.insert(p+x);
        }
        perv = ans[x];
        while (!st.empty()){
            ll p = *(st.begin());
            if (p <= x) st.erase(st.begin());
            else break;
        }
    }
    st.clear();
    reverse(all(ve));
    perv = 0;
    f = -1;
    ll mx = 0;
    for (ll x : ve){
        perv -= st.size()*(f-x);
        ans[x] += perv;
        if (ans[x] > m+1000000000){
            ans.clear();
            mp.clear();
            rep(i,0,n) cout << 0;
            cout << endl;
            return;
        }
        f = x;
        mx = max(mx,ans[x]);
        for (ll p : mp[x]){
            st.insert(p-x);
            perv += p;
        }
        while (!st.empty()){
            ll p = *(st.begin());
            if (p+x <= 0) st.erase(st.begin());
            else break;
        }
    }
    if (mx <= m){
        rep(i,0,n) cout << 1;
        cout << endl;
    }
    else{
        int sz = ve.size();
        reverse(all(ve));
        if (ans[ve[0]] > m) pre[0] = ans[ve[0]]-ve[0];
        else pre[0] = -2*inf;
        if (ans[ve[sz-1]] > m) suf[sz-1] = ans[ve[sz-1]]+ve[sz-1];
        else suf[sz-1] = -2*inf;
        rep(i,1,sz){
            if (ans[ve[i]] > m) pre[i] = max(pre[i-1],ans[ve[i]]-ve[i]);
            else pre[i] = pre[i-1];
        }
        repr(i,sz-2,0){
            if (ans[ve[i]] > m) suf[i] = max(suf[i+1],ans[ve[i]]+ve[i]);
            else suf[i] = suf[i+1];
        }
        rep(i,0,n){
            int ind = lower_bound(all(ve),b[i])-ve.begin();
            if (p[i]-b[i]+m < pre[ind]){
                cout << 0;
                continue;
            }
            if (p[i]+b[i]+m < suf[ind]){
                cout << 0;
                continue;
            }
            cout << 1;
        }
        cout << endl;
    }
    ans.clear();
    mp.clear();
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