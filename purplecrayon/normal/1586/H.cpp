#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;


int n, q, a[MAXN], par[MAXN];
ar<ll, 5> ed[MAXN], sed[MAXN];
vector<int> st[MAXN], id[MAXN];
vector<int> order, eid;
int loc_ed[MAXN], loc_nod[MAXN];

ar<ll, 2> qs[MAXN];
pair<int, ll> ans[MAXN];

int p[MAXN], sz[MAXN];
pair<ll, int> mn[MAXN], mx[MAXN];

int find_set(int v){ 
    return v == p[v] ? v : p[v] = find_set(p[v]);
}
void merge(int a, int b) {
    if ((a = find_set(a)) == (b = find_set(b))) {
        assert(false); // tree
        return;
    }
    if (sz[a] < sz[b]) swap(a, b);
    if (mn[a].first != mn[b].first) {
        mn[a] = max(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    } else {
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    }
    p[b] = a, sz[a] += sz[b];
}
vector<ll> w;
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
    RMQ(){}
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
RMQ<ll> rmq;

ll qry(int a, int b) {
    if (a > b) swap(a, b);
    if (a == b) return 0;
    return rmq.query(a, b);
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; ll c, d; cin >> a >> b >> c >> d, --a, --b;
        ed[i] = {a, b, c, d, i}, sed[i] = {a, b, c, d, i};
    }
    sort(sed, sed+n-1, [&](auto a, auto b){ return a[3] < b[3]; });
    iota(par, par+n, 0);
    for (int i = 0; i < n; i++) {
        st[i].push_back(i);
    }
    for (int i = 0; i < n-1; i++) {
        auto [a, b, _, w, cid] = sed[i];
        a = par[a], b = par[b];
        if (sz(st[a]) < sz(st[b])) swap(a, b);

        id[a].push_back(cid);
        for (auto v : id[b]) id[a].push_back(v);
        id[b].clear();

        for (auto v : st[b]) {
            par[v] = a;
            st[a].push_back(v);
        }
        st[b].clear();
    }
    const int ROOT = par[0];
    order = st[ROOT], eid = id[ROOT];

    for (int i = 0; i < n-1; i++) loc_ed[eid[i]] = i;
    for (int i = 0; i < n; i++) loc_nod[order[i]] = i;
    for (int i = 0; i < sz(eid); i++) w.push_back(ed[eid[i]][3]);
    rmq = RMQ<ll>(w);

    for (int i = 0; i < q; i++) {
        cin >> qs[i][0] >> qs[i][1], --qs[i][1];
    }

    vector<pair<ll, int>> all;
    for (int i = 0; i < n-1; i++) {
        all.emplace_back(ed[i][2], i+q);
    }
    for (int i = 0; i < q; i++) {
        all.emplace_back(qs[i][0], i);
    }
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
        mn[i] = mx[i] = make_pair(a[i], loc_nod[i]);
    }
    sort(all.rbegin(), all.rend());
    for (auto [_, c] : all) {
        if (c < q) { // qry
            int node = qs[c][1];
            int root = find_set(node);

            ans[c].first = mn[root].first;
            assert(mn[root].first == mx[root].first);
            ans[c].second = max(qry(mn[root].second, loc_nod[node]), qry(mx[root].second, loc_nod[node]));
        } else {
            c -= q;
            int a = ed[c][0], b = ed[c][1];
            merge(a, b);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}