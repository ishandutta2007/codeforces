#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15 + 7;
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> gr[N];
ll s[N];
int n;

pair<ll, ll> dfs(int u, int k) {
    ll res = k * s[u];
    vector<ll> opt{0};
    for (int to : gr[u]) {
        auto tmp = dfs(to, k / size(gr[u]));
        res += tmp.first;
        opt.push_back(tmp.second);
    }
    sort(all(opt));
    reverse(all(opt));

    int cal = (size(gr[u]) ? k % size(gr[u]) : 0);
    for (int i = 0; i < cal; ++i)
        res += opt[i];

    return {res, opt[cal] + s[u]};
}

void run() {
    int k; 
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        gr[i].clear();
    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p;
        gr[p].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    cout << dfs(0, k).first << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}