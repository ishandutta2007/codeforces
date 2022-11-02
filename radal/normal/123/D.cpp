#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
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
const long long int N = 3e5+20,mod = 1e9+9,mod2 = 1e9+7,inf = 1e18+10,maxm= (1 << 21);
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
string s;
int hsh[N],n,pw[N],a[N],l[N],r[N];;
vector<int> suf;
inline int bs(int i,int j){
    int l = -1,r = n-max(i,j),m;
    while (r-l > 1){
        m = (l+r) >> 1;
        int g1,g2;
        g1 = hsh[i+m];
        g2 = hsh[j+m];
        if (i){
            g1 = mkay(g1,-1ll*hsh[i-1]*pw[m+1]%mod);
        }
        if (j){
            g2 = mkay(g2,-1ll*hsh[j-1]*pw[m+1]%mod);
        }
        if (g1 == g2) l = m;
        else r = m;
    }
    return r;
}
bool cmp(int i,int j){
    int x = bs(i,j);
    if (max(i,j)+x >= n)
        return (i > j);
    return (s[i+x] < s[j+x]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    pw[0] = 1;
    rep(i,0,n){
        pw[i+1] = 1ll*pw[i]*359%mod;
        suf.pb(i);
        hsh[i] = s[i]-'a'+1;
        if (i){
            hsh[i] = mkay(hsh[i],1ll*hsh[i-1]*359%mod);
        }
    }
    sort(suf.begin(),suf.end(),cmp);
    rep(i,1,n)
        a[i] = bs(suf[i],suf[i-1]);
    stack<int> st;
    st.push(0);
    rep(i,1,n){
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        l[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    repr(i,n-1,1){
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) r[i] = st.top();
        else r[i] = n;
        st.push(i);
    }
    ll ans = (1ll*n*(n+1)/2);
    rep(i,1,n){
        ans += 1ll*(r[i]-l[i])*(r[i]-l[i]-1)/2*(a[i]-max(a[l[i]],a[r[i]]));
    }
    cout << ans;
 }