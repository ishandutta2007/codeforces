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

const int nax = 5e5 + 5;
const int roz = (1 << 20);

ll a[4][nax];
ll pref[nax];
ll suf[nax];
ll sec[nax];
int n, q;
const ll inf = 1e18;

vector<tuple<int, int, int> > Q;
vector<pii> zap[nax];

struct node{
    ll faa, fab, fac, fbb, fbc, fcc;
    ll sb, sc;
};

node combine(node a, node b){
    if(a.faa == -inf) return b;
    if(b.faa == -inf) return a;
    node res;
    res.faa = a.faa + b.faa;
    res.fbb = a.fbb + b.fbb;
    res.fcc = a.fcc + b.fcc;
    res.fab = max(a.faa + b.fab, a.fab + b.fbb);
    res.fbc = max(a.fbb + b.fbc, a.fbc + b.fcc);
    res.fac = max({a.faa + b.fac, a.fab + b.fbc, a.fac + b.fcc});

    res.sb = max({a.sb + b.fbb, b.sb});
    res.sc = max({b.sc, a.sb + b.fbc, a.sc + b.fcc});

    return res;
}

node tree[roz];
node emp;


node ask(int lo, int hi, int u, int a, int b){
    if(lo == a && b == hi) return tree[u];
    if(b <= a) return emp;
    int mid = (lo + hi) / 2;
    auto L = ask(lo, mid, u * 2, a, min(b, mid));
    auto R = ask(mid, hi, u * 2 + 1, max(a, mid), b);
    return combine(L, R);
}

ll tree2[roz];
ll lazy[roz];
bool marked[roz];

void push(int v){
    if(marked[v]){
        for(int i=v*2;i<=v*2+1;i++){
            marked[i] = true;
            lazy[i] += lazy[v];
            tree2[i] += lazy[v];
        }
        marked[v] = false;
        lazy[v] = 0;
    }
}

void add2(int lo, int hi, int u, int a, int b, ll c){
    if(lo == a && b == hi){
        tree2[u] += c;
        lazy[u] += c;
        marked[u] = true;
        return;
    }
    if(b <= a) return;
    int mid = (lo + hi) / 2;
    push(u);
    add2(lo, mid, u * 2, a, min(b, mid), c);
    add2(mid, hi, u * 2 + 1, max(a, mid), b, c);
    tree2[u] = max(tree2[u * 2], tree2[u * 2 + 1]);
}

ll ask2(int lo, int hi, int u, int a, int b){
    if(lo == a && b == hi) return tree2[u];
    if(b <= a) return -inf;
    push(u);
    int mid = (lo + hi) / 2;
    ll L = ask2(lo, mid, u * 2, a, min(b, mid));
    ll R = ask2(mid, hi, u * 2 + 1, max(a, mid), b);
    return max(L, R);
}

ll dp[nax];

void solve(){
    emp.faa = -inf;
    cin >> n >> q;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
    for(int i=1;i<=n;i++) pref[i] = pref[i - 1] + a[1][i];
    for(int i=n;i>=1;i--) suf[i] = suf[i + 1] + a[3][i];
    for(int i=1;i<=n;i++) sec[i] = sec[i - 1] + a[2][i];
    for(int i=1;i<=q;i++){
        int l, r, k; cin >> l >> r >> k;
        Q.pb(make_tuple(l, r, k));
        zap[r].pb(mp(l, k));
    }

    for(int i=0;i<=n;i++) dp[i] = -inf;
    // add2(0, roz / 2, 1, 0, 1, -inf);
    for(int i=1;i<=n;i++){
        for(auto cur : zap[i]){
            int lo = cur.st;
            int cost = cur.nd;
            ll best = ask2(0, roz / 2, 1, lo, i);
            best += a[2][i];
            best -= cost;
            dp[i] = max(dp[i], best);
            dp[i] = max(dp[i], pref[i] + a[2][i] - cost);
            ll moze = dp[lo - 1] + sec[i] - sec[lo - 1] - cost;
            dp[i] = max(dp[i], moze);
        }
        ll can = pref[i] + a[2][i];
        ll ins = max(can, dp[i]);
        add2(0, roz / 2, 1, 1, i, a[2][i]);
        add2(0, roz / 2, 1, i, i + 1, ins);
    }

    for(int i=1;i<=n;i++){
        node cur;
        cur.faa = a[1][i];
        cur.fbb = a[2][i];
        cur.fcc = a[3][i];
        cur.fab = a[1][i] + a[2][i];
        cur.fbc = a[2][i] + a[3][i];
        cur.fac = a[1][i] + a[2][i] + a[3][i];

        cur.sb = dp[i];
        cur.sc = dp[i] + a[3][i];

        tree[roz / 2 + i] = cur;
    }
    for(int i=roz/2-1;i>=1;i--) tree[i] = combine(tree[i * 2], tree[i * 2 + 1]);
    ll ans = -inf;

    for(auto [L, R, cost] : Q){
        auto g = ask(0, roz / 2, 1, L, R + 1);
        ll only = g.fac + pref[L - 1] + suf[R + 1];
        g = ask(0, roz / 2, 1, max(1, L - 1), R + 1);
        ll ktos = g.sc + suf[R + 1];
        ll best = max(only, ktos) - cost;
        ans = max(ans, best);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}