#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <random>
#include <ctime>

typedef long long ll;

using namespace std;

vector <ll> t;
vector <pair <ll, ll>> e;
unordered_map <ll, vector <ll>> pos, birth;
unordered_map <ll, ll> frst;
vector <ll> dsu, dsu_rank, dsu_sz;
vector <vector <ll>> tree;

void add(ll v, ll tl, ll tr, ll l, ll r, ll pos) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[v].push_back(pos);
        return;
    }
    ll tm = (tl + tr) / 2;
    add(v * 2, tl, tm, l, min(tm, r), pos);
    add(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, pos);
}

ll get(ll v) {
    if (dsu[v] == v) return v;
    return get(dsu[v]);
}

void dsu_merge(ll u, ll v, vector <pair<ll, pair<ll, pair <ll, ll>>>> &upd, ll &comp) {
    u = get(u);
    v = get(v);
    if (u != v) comp--;
    if (u == v) return;
    if (dsu_rank[u] < dsu_rank[v])
        swap(u, v);
    upd.push_back({ v, {u, {dsu_rank[u], dsu_sz[u]} } });
    if (dsu_rank[u] == dsu_rank[v]) ++dsu_rank[u];
    dsu_sz[u] += dsu_sz[v];
    dsu[v] = u;
}

void solve(ll v, ll tl, ll tr, vector <pair <ll, ll>> &e, vector <ll> &ans, ll comp, vector <ll> &compsz) {
    vector <pair<ll, pair<ll, pair <ll, ll>>>> upd;
    for (ll i = 0; i < tree[v].size(); i++)
        dsu_merge(e[tree[v][i]].first, e[tree[v][i]].second, upd, comp);
    if (tl == tr) {
        ans[tl] = dsu_sz[get(compsz[tl])];
        for (ll i = (ll)upd.size() - 1; i >= 0; i--) {
            dsu[upd[i].first] = upd[i].first;
            dsu_rank[upd[i].second.first] = upd[i].second.second.first;
            dsu_sz[upd[i].second.first] = upd[i].second.second.second;
        }
        return;
    }
    ll tm = (tl + tr) / 2;
    solve(v * 2, tl, tm, e, ans, comp, compsz);
    solve(v * 2 + 1, tm + 1, tr, e, ans, comp, compsz);
    for (ll i = (ll)upd.size() - 1; i >= 0; i--) {
      dsu[upd[i].first] = upd[i].first;
      dsu_rank[upd[i].second.first] = upd[i].second.second.first;
      dsu_sz[upd[i].second.first] = upd[i].second.second.second;
    }
}

mt19937_64 gen(time(0));

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q, k;
    cin >> n >> q >> k;
    if (q == 0) return 0;
    tree.resize(8 * q + 10);
    ll cnt = -1;
    vector <vector <pair <int, int>>> old_e(q);
    vector <ll> compsz(1e6);
    int cur_day = 0;
    for (ll i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 2) {
          t.push_back(++cnt);
          int z;
          cin >> z;
          compsz[cnt] = z - 1;
        }
        if (type == 1) {
            ++cnt;
            ll u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            ll hash = n * u + v;
            old_e[cur_day].push_back({u, v});
            pos[hash].push_back(e.size());
            birth[hash].push_back(cnt);
            if (frst.find(hash) == frst.end())
              frst[hash] = 0;
            e.push_back({ u, v });
        }
        if (type == 3) {
            ++cur_day;
            if (cur_day - k < 0)
              continue;
            for (auto &now : old_e[cur_day - k]) {
                ++cnt;
                ll u, v;
                u = now.first, v = now.second;
                if (u > v) swap(u, v);
                ll hash = n * u + v;
                add(1, 0, 2 * q - 1, birth[hash][frst[hash]], cnt, pos[hash][frst[hash]]);
                frst[hash]++;
            }
        }
    }
    for (auto now : pos) {
        ll hash = now.first;
        while (frst[hash] < (ll)birth[hash].size()) {
          add(1, 0, 2 * q - 1, birth[hash][frst[hash]], 2 * q - 1, now.second[frst[hash]]);
          frst[hash]++;
        }
    }
    ll comp = n;
    dsu.resize(n), dsu_rank.resize(n), dsu_sz.resize(n, 1);
    iota(dsu.begin(), dsu.end(), 0);
    vector <ll> ans(3 * q);
    solve(1, 0, 2 * q - 1, e, ans, comp, compsz);
    for (ll i = 0; i < t.size(); i++)
        cout << ans[t[i]] << endl;
    return 0;
}