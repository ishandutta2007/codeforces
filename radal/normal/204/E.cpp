#define __GLIBCXX_DEBUG 1
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
int n,k;
vector<int> hsh[N];
int c[N],pw[N],sz[N],ok[N],l[N],r[N],ps[N];
ll ans[N];
string s[N];
inline int bs(pll x,pll y){
    int i = x.Y,j = y.Y,a = x.X,b = y.X;
    int l = -1,r = min(sz[a]-i,sz[b]-j),m;
    while (r-l > 1){
        m = (l+r) >> 1;
        int g1,g2;
        g1 = hsh[a][i+m];
        g2 = hsh[b][j+m];
        if (i){
            g1 -= 1ll*hsh[a][i-1]*pw[m+1]%mod;
            if(g1 < 0) g1 += mod;
        }
        if (j){
            g2 -= 1ll*hsh[b][j-1]*pw[m+1]%mod;
            if (g2 < 0) g2 += mod;
        }
        if (g1 == g2) l = m;
        else r = m;
    }
    return r;
}
inline bool cmp(pll i,pll j){
    int x = sz[i.X]-i.Y,y = sz[j.X]-j.Y;
    int z = bs(i,j);
    if (min(x,y) <= z)
        return (y > x);
    return (s[i.X][i.Y+z] < s[j.X][j.Y+z]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    pw[0] = 1;
    vector<pll> ve;
    rep(i,0,n){
        cin >> s[i];
        sz[i] = s[i].size();
        int m = sz[i];
        hsh[i].resize(m);
        rep(j,0,m){
            ve.pb({i,j});
            pw[j+1] = 1ll*359*pw[j]%mod;
            hsh[i][j] = s[i][j]-'a'+1;
            if (j) hsh[i][j] = mkay(hsh[i][j],1ll*hsh[i][j-1]*359%mod);
        }
    }
    if (k == 1){
        rep(i,0,n){
            cout << 1ll*sz[i]*(sz[i]+1)/2 << ' ';
        }
        return 0;
    }
    sort(ve.begin(),ve.end(),cmp);
    int siz = ve.size();
    rep(i,1,siz) c[i] = bs(ve[i],ve[i-1]);
    stack<int> st;
    rep(i,1,siz){
        while (!st.empty() && c[st.top()] > c[i]) st.pop();
        if (st.empty()) l[i] = 0;
        else l[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    repr(i,siz-1,1){
        while (!st.empty() && c[st.top()] >= c[i]) st.pop();
        if (st.empty()) r[i] = siz;
        else r[i] = st.top();
        st.push(i);
    }
    map<int,int> mp;
    ok[siz] = siz+2;
    repr(i,siz-1,0){
        mp[ve[i].X]++;
        ok[i] = ok[i+1];
        while (int(mp.size()) > k || (int(mp.size()) == k && (ok[i] >= siz || mp[ve[ok[i]].X] > 1))){
            if (ok[i] >= siz){
                ok[i]--;
                continue;
            }
            mp[ve[ok[i]].X]--;
            if (mp[ve[ok[i]].X] == 0)
                mp.erase(ve[ok[i]].X);
            ok[i]--;
        }
    }
    rep(i,1,siz){
        if (ok[l[i]] < r[i]){
            ps[l[i]] += c[i]-max(c[l[i]],c[r[i]]);
            ps[r[i]] -= (c[i]-max(c[l[i]],c[r[i]]));
        }
    }
    rep(i,0,siz){
        ps[i+1] += ps[i];
        ans[ve[i].X] += ps[i];
    }
    rep(i,0,n) cout << ans[i] << ' ';
}