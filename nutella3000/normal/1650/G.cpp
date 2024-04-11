#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define siz(bit) (int)bit.size()
#define all(bit) begin(bit), end(bit)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& bit, int b){ if(bit > b){ bit = b; return 1; } return 0; }
bool chmax(int& bit, int b){ if(bit < b){ bit = b; return 1; } return 0; }
   
   
   
mt19937 Rand(time(0));
int rnd(int bit) { return Rand() % bit; }
int rnd(int bit, int b) { return Rand() % (b - bit + 1) + bit; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }
   
const int inf = 1e15 + 7, mod = 1e9 + 7;
const int N = 2e5 + 3;

int n, m, S, T;
vector<int> gr[N];

pair<vector<int>, vector<int>> dij(int s) {
    vector<int> d(n, inf), c(n), used(n);
    d[s] = 0, c[s] = 1;
    deque<int> so;
    so.pb(s);

    while (siz(so)) {
        int v = *so.begin(); so.pop_front();
        if (used[v]) continue;
        used[v] = true;
        for (int to : gr[v]) {
            if (d[to] < d[v] + 1) continue;
            if (d[to] > d[v] + 1) c[to] = 0;

            d[to] = d[v] + 1;
            c[to] = (c[to] + c[v]);
            if (c[to] >= mod) c[to] -= mod;
            so.pb(to);
        }
    }

    return {d, c};
}

void run() {
    cin >> n >> m >> S >> T; --S, --T;
    for (int i = 0; i < n; ++i)
        gr[i].clear();
    for (int i = 0; i < m; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].pb(v2);
        gr[v2].pb(v1);
    }

    auto dS = dij(S);
    auto dT = dij(T);

    int res = dS.se[T];
    for (int i = 0; i < n; ++i) {
        for (int j : gr[i]) {
            if (dS.fi[i] + dT.fi[j] == dS.fi[T] && dS.fi[i] + dT.fi[i] == dS.fi[T]) {
                res = (res + dS.se[i] * dT.se[j]) % mod;
            }
        }
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}