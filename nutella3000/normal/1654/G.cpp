#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T>  bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }


const int inf = 1e9 + 7;
const int N = 2e5 + 3;

int n;
vector<int> gr[N];
int d[N], good[N], res[N];

void bfs() {
    deque<int> bfs;
    for (int i = 0; i < n; ++i)
        if (!d[i]) bfs.eb(i);
    while (siz(bfs)) {
        int v = bfs.front(); bfs.pop_front();
        for (int to : gr[v]) {
            if (d[to] == inf) {
                d[to] = d[v] + 1;
                bfs.eb(to);
            }
        }
    }
}

void solve(int h) {
    vector<int> pot(n, inf);
    auto comp = [&](int v1, int v2) {
        return mp(pot[v1], v1) < mp(pot[v2], v2);
    };
    set<int, decltype(comp)> dij(comp);
    for (int i = 0; i < n; ++i) {
        if (good[i] && d[i] == h) {
            pot[i] = 0;
            dij.emplace(i);
        }
    }
    while (siz(dij)) {
        int v = *dij.begin(); dij.erase(dij.begin());
        //cout << v+1 << " " << pot[v] << endl;
        for (int to : gr[v]) {
            if (d[to] < d[v]) continue;

            int c = (d[to] > d[v] ? -1 : 1);
            int e = max(0ll, pot[v] + c);
            if (pot[to] >= e) {
                dij.erase(to);
                pot[to] = e;
                dij.emplace(to);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (pot[i] == 0) chmin(res[i], h);
}

void run() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v; d[i] = (v ? 0 : inf);
    }
    for (int i = 0; i < n-1; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].eb(v2); gr[v2].eb(v1);
    }
    bfs();

    set<int> gh;
    for (int i = 0; i < n; ++i) {
        for (int to : gr[i])
            if (d[to] == d[i]) good[i] = true;
        if (good[i]) gh.emplace(d[i]);
    }

    fill(res, res + n, inf);
    for (int h : gh) {
        //cout << "wtf " << h << endl;
        solve(h);
    }
    for (int i = 0; i < n; ++i) {
        chmin(res[i], d[i]);
        cout << 2*d[i] - res[i] << " ";
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}