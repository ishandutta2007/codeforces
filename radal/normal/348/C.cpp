#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,fx = 310+10;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    int r = poww(a,k/2);
    return 1ll*r*r%mod*poww(a,k&1)%mod;
}
vector<int> s[N];
int sz[N],e[N][fx];
ll sm[N],delta[N],a[N];
bitset<N> b[fx];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q,cnt=0;
    cin >> n >> m >> q;
    rep(i,1,n+1) cin >> a[i];
    vector<int> big;
    big.reserve(200);
    rep(i,1,m+1){
        cin >> sz[i];
        s[i].reserve(100);
        int x;
        rep(j,0,sz[i]){
            cin >> x;
            sm[i] += a[x];
            s[i].pb(x);
        }
        if (sz[i] > fx){
            big.pb(i);
            for (int u : s[i]) b[cnt][u] = 1;
            cnt++;
        }
    }
    rep(i,1,m+1){
        rep(j,0,cnt)
            for (int u : s[i]) if (b[j][u]) e[i][j]++;
    }
    while (q--){
        char c;
        int k;
        cin >> c >> k;
        if (c == '?'){
            ll ans = 0;
            if (sz[k] > fx){
                ans = sm[k];
                rep(i,0,cnt) ans += 1ll*delta[big[i]]*e[k][i];
                cout << ans << endl;
                continue;
            }
            for (int u : s[k]) ans += a[u];
            rep (j,0,cnt)
                ans += 1ll*delta[big[j]]*e[k][j];
            cout << ans << endl;
            continue;
        }
        int x;
        cin >> x;
        if (sz[k] > fx){
            delta[k] += x;
            continue;
        }
        rep(i,0,cnt)
            sm[big[i]] += 1ll*x*e[k][i];
        rep(i,0,sz[k])
            a[s[k][i]] += x;
    }
}