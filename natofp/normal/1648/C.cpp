#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int mod = 998244353;
const int nax = 2e5 + 5;
int a[nax];
int bb[nax];
int cnt[nax];
int n, m;

ll pp(ll a, ll b){
    if(b==0) return 1;
    ll ac = pp(a,b/2);
    ac*=ac;
    ac%=mod;
    if(b&1){
        ac*=a;
        ac%=mod;
    }
    return ac;
}
ll ii(ll a){
    return pp(a,mod-2);
}

ll f[nax];
ll iw[nax];

void prep(){
    f[0] = 1;
    iw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = f[i - 1] * i;
        f[i] %= mod;
        iw[i] = ii(f[i]);
    }
}

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ret += bit[r];
            ret %= mod;
        }
        return ret;
    }

    int sum(int l, int r) {
        return (sum(r) - sum(l - 1) + mod) % mod;
    }

    void add(int idx, int delta) {
        if(delta < 0) delta += mod;
        for (; idx < n; idx = idx | (idx + 1)){
            bit[idx] += delta;
            bit[idx] %= mod;
        }
    }
};

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    for(int i=1;i<=m;i++) cin >> bb[i];
    ll ans = 0;
    int b = min(n - 1, m - 1);
    FenwickTree tri(nax + 5);
    for(int i=0;i<nax;i++){
        tri.add(i, cnt[i]);
    }
    ll cur = f[n];
    for(int i=1;i<nax;i++){
        cur *= iw[cnt[i]];
        cur %= mod;
    }
    for(int i=0;i<=b;i++){
        int w = bb[i + 1];
        int g = tri.sum(w - 1);
        ll nxt = cur;
        nxt *= ii(n - i);
        nxt %= mod;
        nxt *= g;
        ans += nxt;
        ans %= mod;
        if(cnt[w] == 0) break;
        else{
            cur *= ii(n-i);
            cur %= mod;
            cur *= cnt[w];
            cur %= mod;
            cnt[w] -= 1;
            tri.add(w,-1);
        }
    }
    // czy mozemy byc rowni?
    if(n < m){
        map<int, int> es;
        for(int i=1;i<=n;i++) es[bb[i]] += 1;
        bool ok = true;
        for(int i=1;i<=n;i++){
            es[a[i]] -= 1;
            if(es[a[i]] < 0) ok = false;
        }
        ans += ok;
        ans %= mod;
    }
    cout<<ans<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}