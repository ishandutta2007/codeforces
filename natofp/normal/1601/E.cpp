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

std::pair<ll, ll> operator +(const std::pair<ll, ll>& x, const std::pair<ll, ll>& y) {
    return std::make_pair(x.first + y.first, x.second + y.second);
}

const int nax = 3e5 + 5;

int t[nax][18], a[nax];
void build(int n) {
  for(int i = 1; i <= n; ++i) t[i][0] = a[i];
  for(int k = 1; k < 18; ++k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
      t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(t[l][k], t[r - (1 << k) + 1][k]);
}

int n, q, k;

const int roz = (1 << 20);
ll tree[roz];
pll lazy[roz];
bool mark[roz];
int sz[roz];

ll ary(ll lo, ll prog, ll cnt){
    return (lo + (lo + (cnt - 1) * prog)) * cnt / 2;
}

void push(ll v){
    if(mark[v]){
        lazy[v * 2] = lazy[v * 2] + lazy[v];
        lazy[v * 2 + 1] = lazy[v * 2 + 1] + lazy[v];
        lazy[v * 2 + 1].st += lazy[v].nd * sz[v * 2];
        mark[v * 2] = mark[v * 2 + 1] = true;
        tree[v * 2] += ary(lazy[v].st, lazy[v].nd, sz[v * 2]);
        tree[v * 2 + 1] += ary(lazy[v].st + lazy[v].nd * sz[v * 2], lazy[v].nd, sz[v * 2 + 1]);
        mark[v] = false;
        lazy[v] = mp(0, 0);
    }
}

void upd(int lo, int hi, int u, int a, int b, pll val){
    if(lo == a && b == hi){
        lazy[u] = lazy[u] + val;
        tree[u] += ary(val.st, val.nd, hi - lo);
        mark[u] = true;
        return;
    }
    if(b <= a) return;
    push(u);
    int mid = (lo + hi) / 2;
    upd(lo, mid, u * 2, a, min(b, mid), val);
    pll go = mp(val.st + val.nd * max(0, mid - a) , val.nd);
    upd(mid, hi, u * 2 + 1, max(a, mid), b, go);
    tree[u] = tree[u * 2] + tree[u * 2 + 1];
}

ll ask(int lo, int hi, int u, int a, int b){
    if(lo == a && b == hi){
        return tree[u];
    }
    if(b <= a) return 0;
    push(u);
    int mid = (lo + hi) / 2;
    ll L = ask(lo, mid, u * 2, a, min(b, mid));
    ll R = ask(mid, hi, u * 2 + 1, max(a, mid), b);
    return L + R;
}



void ini(){
    for(int i=roz/2;i<roz;i++) sz[i] = 1;
    for(int i=roz/2-1;i>=1;i--) sz[i] = sz[i * 2] + sz[i * 2 + 1];
}

vector<pii> que[nax];
ll ans[nax];

void solve(){
    cin >> n >> q >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    build(n);
    ini();

    for(int i=1;i<=q;i++){
        int l, r; cin >> l >> r;
        int ent = l % k;
        if(r % k < ent){
            r -= (r % k + 1);
        }
        if(r % k >= ent) r -= (r % k - ent);
        que[l].pb(mp(r, i));
    }

    for(int mod=0;mod<k;mod++){ // TODO
        int last = n;
        if(last % k < mod){
            last -= (last % k + 1);
        }
        last -= (last % k - mod);
        int cur = last;
        stack<pll> alive; // VALUE, HOW LONG IT GOES FOR
        int mappedIndex = last / k;
        int bound = mappedIndex;
        while(cur >= 1){
            int valueForNextIntervals = query(cur, min(n, cur + k));
            if(cur + k > n) valueForNextIntervals = 2e9;
            int offsetGone = 0;
            while(alive.size() && alive.top().st >= valueForNextIntervals){
                auto akt = alive.top(); alive.pop();
                int len = akt.nd;

                upd(0, roz / 2, 1, mappedIndex + offsetGone + 1, mappedIndex + offsetGone + len + 1, mp(-akt.st, -akt.st));
                upd(0, roz / 2, 1, mappedIndex + offsetGone + len + 1, bound + 1, mp(-akt.st * len, 0));
                offsetGone += len;
            }

            if(offsetGone) alive.push(mp(valueForNextIntervals, offsetGone));
            int val2 = a[cur];
            alive.push(mp(val2, 1));
            upd(0, roz / 2, 1, mappedIndex, bound + 1, mp(val2, 0));
            upd(0, roz / 2, 1, mappedIndex + 1, mappedIndex + offsetGone + 1, mp(valueForNextIntervals, valueForNextIntervals));
            upd(0, roz / 2, 1, mappedIndex + offsetGone + 1, bound + 1, mp((ll)valueForNextIntervals * offsetGone, 0LL));

            for(pii q : que[cur]){
                int to = q.st;
                int id = q.nd;
                ll ac = ask(0, roz / 2, 1, to / k, to / k + 1);
                ans[id] = ac;
            }

            mappedIndex -= 1;
            cur -= k;
        }
        int offsetGone = 0;
        while(alive.size()){
            auto akt = alive.top(); alive.pop();
            int len = akt.nd;

            upd(0, roz / 2, 1, mappedIndex + offsetGone + 1, mappedIndex + offsetGone + len + 1, mp(-akt.st, -akt.st));
            upd(0, roz / 2, 1, mappedIndex + offsetGone + len + 1, bound + 1, mp(-akt.st * len, 0));
            offsetGone += len;
        }
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}