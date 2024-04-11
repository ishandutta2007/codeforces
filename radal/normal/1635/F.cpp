#include <bits/stdc++.h>
//#pragma GCC target("popcnt")
//#pragma GCC optimize("unroll-loops")
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
constexpr int N = 6e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
int x[N],w[N];
vector<int> seg[N];
vector<pll> Q[N];
ll fen[N],ans[N];
void upd(int l,ll x){
    for (; l < N; l |= (l+1))
        fen[l] = min(fen[l],x);
}
ll que(int r){
    ll ans = 4ll*inf*inf;
    for (; r >= 0; r = (r&(r+1))-1)
        ans = min(ans,fen[r]);
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(fen,63,sizeof fen);
    int n,q;
    cin >> n >> q;
    stack<int> st;
    rep(i,0,n){
        cin >> x[i] >> w[i];
        while (!st.empty() && w[st.top()] > w[i]) st.pop();
        if(!st.empty())
            seg[i].pb(st.top());
        st.push(i);
    }
    while (!st.empty()) st.pop();
    repr(i,n-1,0){
        while (!st.empty() && w[st.top()] > w[i]) st.pop();
        if(!st.empty())
            seg[st.top()].pb(i);
        st.push(i);
    }
    rep(i,0,q){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        Q[r].pb({l,i});
    }
    rep(i,0,n){
        for(int j : seg[i]){
            upd(n-j,1ll*(x[i]-x[j])*(w[i]+w[j]));
        }
        for (pll p : Q[i]){
            ans[p.Y] = que(n-p.X);
        }
    }
    rep(i,0,q) cout << ans[i] << endl;
}