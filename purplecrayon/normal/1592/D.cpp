#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

vector<ar<int, 2>> tree[MAXN];
int dfs_get(int c, int p, int cur, set<int>& s) {
    int ans = 0;
    if (s.count(c)) ans = cur;
    for (auto [nxt, x] : tree[c]) if (nxt != p) {
        ans = max(ans, dfs_get(nxt, c, gcd(cur, x), s));
    }
    return ans;
}
int judge(vector<int> v) {
    set<int> s(v.begin(), v.end());
    int ans = 0;
    for (auto c : v) {
        ans = max(ans, dfs_get(c, -1, 0, s));
    }
    return ans;
}


int n, m;
vector<ar<int, 2>> ed;
vector<ar<int, 2>> one, two;
vector<int> adj[MAXN];
bool vis[MAXN];

int cnt_queries = 0;

int qry(vector<int> v) { 
    cnt_queries++;
    assert(cnt_queries <= 12);
#ifdef LOCAL
    return judge(v);
#endif
    cout << "? " << sz(v);
    for (auto c : v) cout << ' ' << c+1;
    cout << endl;
    int d; cin >> d;
    return d;
}

void dfs(int c) {
    vis[c] = 1;
    for (auto nxt : adj[c]) if (!vis[nxt]) {
        if (m)
            one.push_back({c, nxt}), m--;
        else
            two.push_back({c, nxt});

        dfs(nxt);
    }
}

vector<int> get(vector<ar<int, 2>> c) {
    set<int> s;
    for (auto [a, b] : c) s.insert(a), s.insert(b);
    return vector<int>(s.begin(), s.end());
}
void solve() {
    srand(time(0));
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
#ifdef LOCAL
        int me = (rand()%2+2)*(rand()%100+1);
        tree[a].push_back({b, me});
        tree[b].push_back({a, me});
        cerr << a << ' ' << b << ' ' << me << endl;
#endif

        ed.push_back({a, b});
    }
    vector<int> v(n); iota(v.begin(), v.end(), 0);
    int d = qry(v);
    while (sz(ed) > 1) {
        m = sz(ed) / 2;
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < sz(ed); i++) {
            auto [a, b] = ed[i];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(vis, 0, sizeof(vis));
        one.clear(), two.clear();
        for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

        if (qry(get(one)) == d) {
            ed = one;
        } else {
#ifdef LOCAL
            assert(judge(get(two)) == d);
#endif
            ed = two;
        }
    }
#ifdef LOCAL
    assert(judge({ed[0][0], ed[0][1]}) == d);
#endif
    cout << "! " << ed[0][0]+1 << ' ' << ed[0][1]+1 << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}