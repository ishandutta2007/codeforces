#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 5e5 + 100;
const LL Mod = 1000 * 1000 * 1000 + 7;
int par[maxn];
bool mark[maxn];
int n, m;
vector<int> vec;

int root(int u) {
    return par[u] < 0 ? u : par[u] = root(par[u]);
}

bool merge(int u) {
    u = root(u);
    if (mark[u])
        return false;
    return mark[u] = true;
}

bool merge(int u, int v) {
    if ((u = root(u)) == (v = root(v)))
        return false;
    if (mark[u])
        swap(u, v);
    if (mark[u])
        return false;
    if (mark[v])
        return mark[u] = true;
    if (par[u] > par[v])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(par, -1, sizeof par);
    cin >> n >> m;
    LL ans = 1;
    for (int i = 0; i < n; i++) {
        int c;
        int fi, se;
        cin >> c >> fi;
        if (c == 1) {
            fi--;
            if (merge(fi)) {
                ans = ans * 2 % Mod;
                vec.PB(i);
            }
        }
        else {
            cin >> se;
            fi--, se--;
            if (merge(fi, se)) {
                ans = ans * 2 % Mod;
                vec.PB(i);
            }
        }
    }
    cout << ans << ' ' << sz(vec) << '\n';
    for (auto idx: vec)
        cout << idx + 1 << ' ';
    cout << '\n';
    return 0;
}