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
constexpr int N = 2e5+20,mod = 998244353,inf = 1e9+10;
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
int n;
string s,t;
int hsh[N],c[N],r[N],l[N],pw[N];
vector<int> suf;
inline int bs(int i,int j){
    int l = -1,r = n-max(i,j),m;
    while (r-l > 1){
        m = (l+r) >> 1;
        int g1,g2;
        g1 = hsh[i+m];
        g2 = hsh[j+m];
        if (i){
            g1 -= 1ll*hsh[i-1]*pw[m+1]%mod;
            if(g1 < 0) g1 += mod;
        }
        if (j){
            g2 -= 1ll*hsh[j-1]*pw[m+1]%mod;
            if (g2 < 0) g2 += mod;
        }
        if (g1 == g2) l = m;
        else r = m;
    }
    return r;
}
inline bool cmp(int i,int j){
    int x = bs(i,j);
    if (max(i,j)+x >= n)
        return (i > j);
    return (s[i+x] < s[j+x]);
}
int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s >> t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    vector<int> ve;
    ll ans = 0;
    pw[0] = 1;
    rep(i,0,n){
        pw[i+1] = 1ll*257*pw[i]%mod;
        hsh[i] = (s[i]-'a'+1);
        if (i){
            hsh[i] = mkay(1ll*hsh[i-1]*257%mod,hsh[i]);
        }
        if (t[i] == '0'){
            ve.pb(i);
            ans = max(ans,1ll*(n-i));
        }
    }
    sort(ve.begin(),ve.end(),cmp);
    int sz = ve.size();
    stack<int> st;
    st.push(0);
    rep(i,1,sz){
        c[i] = bs(ve[i],ve[i-1]);
        while (!st.empty() && c[st.top()] > c[i]) st.pop();
        l[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    repr(i,sz-1,1){
        while (!st.empty() && c[st.top()] >= c[i]) st.pop();
        if (st.empty()){
            ans = max(ans,1ll*(sz-l[i])*c[i]);
        }
        else{
            ans = max(ans,1ll*(st.top()-l[i])*c[i]);
        }
        st.push(i);
    }
    cout << ans;
	return 0;
}