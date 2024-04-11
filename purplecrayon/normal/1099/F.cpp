#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 5e5+10, MAXL = 20, ALP = 26, MOD = 999244353, MAXK = 110, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

struct Node {
    Node *l, *r;
    ll tl, tr, ts, nm; //sum of times, nm cookies
    void bld(ll _tl, ll _tr){
        tl = _tl, tr = _tr;
        ts=nm=0;
    }
    void extend(){
        if (l || r || tl == tr) return;
        ll tm=(tl+tr)/2;
        l = new Node(), r = new Node();
        l->bld(tl, tm), r->bld(tm+1, tr);
    }
    void add(ll t, ll x){
        if (t < tl || t > tr) return;
        extend();
        ts += t*x, nm += x;
        if (tl != tr) l->add(t, x), r->add(t, x);
    }
    ll qry(ll t){
        if (ts <= t) return nm;
        if (tl == tr) return t/tl;
        if (l->ts >= t) return l->qry(t);
        return l->nm + r->qry(t-(l->ts));
    }
} *st;

int n;
ll T, a[MAXN], t[MAXN];
vector<pair<int, ll>> ch[MAXN];

ll dfs(int c, ll x){
    if (x < 0) return -1e18;
    //add to seg tree
    st->add(t[c], a[c]);
    ll ans = st->qry(x); // = query_segtree
    vector<ll> v;
    for (auto& nxt : ch[c]) v.push_back(dfs(nxt.first, x-2*nxt.second));
    sort(v.begin(), v.end());
    if (!c){ //your move
        ans = max(ans, v.back());
    } else { //edges is erased
        if (sz(v) >= 2){
            ans = max(ans, v[sz(v)-2]);
        }
    }
    //erase from segtree
    st->add(t[c], -a[c]);
    return ans;
}
void solve(){
    //if i start somewhere and move up, eat cookies in increasing order of time
    //ans for cur node is the second max of all states reachable from it (which would be all of it's children)
    //how do i calculate the answer given some node and the amount of time
    //
    //will eat some prefix of the nodes (after being sorted)
    //store in an implicit segtree, (idx would be the time of current)
    //walk down the segment tree to see the number of cookies I can eat
    //
    cin >> n >> T; st = new Node(); st->bld(0, 2e6); 
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 1; i < n; i++){
        int p; ll l; cin >> p >> l, --p;
        ch[p].emplace_back(i, l);
    }
    cout << dfs(0, T) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}