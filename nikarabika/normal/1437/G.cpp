//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

#define ftime fdsd

const int maxn = 300 * 1000 + 1000;
int trien = 1, n, dfstime;
int stime[maxn],
    ftime[maxn],
    value[maxn],
    fail[maxn],
    vert[maxn],
    go[maxn][26];
vector<int> adj[maxn];
string s[maxn];
multiset<int> seg[maxn << 2];

void dfs(int u, int p = -1) {
    stime[u] = dfstime++;
    for (auto v: adj[u])
        if (v != p)
            dfs(v, p);
    ftime[u] = dfstime;
}

int seget(int idx, int l = 0, int r = trien, int id = 1) {
    if (idx < l or r <= idx)
        return -1;
    if (r - l == 1)
        return (sz(seg[id]) ? *seg[id].rbegin(): -1);
    int mid = (l + r) >> 1;
    return max({seget(idx, l, mid, id << 1 | 0),
            seget(idx, mid, r, id << 1 | 1),
            (sz(seg[id]) ? *seg[id].rbegin() : -1)});
}

void segmod(int st, int en, int oldval, int newval, int l = 0, int r = trien, int id = 1) {
    if (st >= r or en <= l)
        return;
    if (st <= l and r <= en) {
        auto it = seg[id].lower_bound(oldval);
        if (it != seg[id].end() and *it == oldval)
            seg[id].erase(it);
        seg[id].insert(newval);
        return;
    }
    int mid = (l + r) >> 1;
    segmod(st, en, oldval, newval, l, mid, id << 1 | 0);
    segmod(st, en, oldval, newval, mid, r, id << 1 | 1);
}

void build_aho() {
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (auto c: s[i]) {
            c -= 'a';
            if (go[cur][c] == -1)
                go[cur][c] = trien++;
            cur = go[cur][c];
        }
        vert[i] = cur;
    }

    vector<int> q;
    for (int i = 0; i < 26; i++)
        if (go[0][i] == -1)
            go[0][i] = 0;
        else {
            fail[go[0][i]] = 0;
            q.PB(go[0][i]);
        }
    for (int i = 0; i < sz(q); i++) {
        int u = q[i];
        for (int j = 0; j < 26; j++)
            if (go[u][j] == -1)
                go[u][j] = go[fail[u]][j];
            else {
                int v = go[u][j];
                fail[v] = go[fail[u]][j];
                q.PB(v);
            }
    }
    for (int i = 1; i < trien; i++)
        adj[fail[i]].PB(i);
    dfs(0);
    
    for (int i = 0; i < n; i++) {
        int u = vert[i];
        segmod(stime[u], ftime[u], -1, 0);
    }
}

int get(string &q) {
    int u = 0;
    int ans = -1;
    for (auto c: q) {
        c -= 'a';
        u = go[u][c];
        ans = max(ans, seget(stime[u]));
    }
    return ans;
}

void modify(int id, int val) {
    int u = vert[id];
    segmod(stime[u], ftime[u], value[id], val);
    value[id] = val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    memset(go, -1, sizeof go);
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    build_aho();
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 2) {
            string quer;
            cin >> quer;
            cout << get(quer) << '\n';
        }
        else {
            int fi, se;
            cin >> fi >> se;
            fi--;
            modify(fi, se);
        }
    }
	return 0;
}