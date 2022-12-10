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

const int maxn = 2 * 100 * 1000 + 10;
const LL INF = 1e18;
LL a[maxn];
map<LL, LL> *ptr[maxn];
int n;
vector<int> adj[maxn];
LL sz[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p, p--;
        adj[p].PB(i);
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int u = n - 1; u >= 0; u--) {
        sz[u] = 1;
        for (auto v: adj[u])
            sz[u] += sz[v];
        sort(all(adj[u]), [](int x, int y) {
                return sz[x] > sz[y];
                });
        if (sz(adj[u])) {
            ptr[u] = ptr[adj[u][0]];
            auto &mp = *ptr[u];
            for (int i = 1; i < sz(adj[u]); i++) {
                int v = adj[u][i];
                for (auto pc: *ptr[v])
                    mp[pc.L] += pc.R;
                delete ptr[v];
            }
            while (a[u] >= mp.begin()->R) {
                auto pc = *mp.begin();
                mp.erase(mp.begin());
                LL space = mp.begin()->L - pc.L;
                LL layers = min(space, a[u] / pc.R);
                mp[pc.L + layers] += pc.R;
                a[u] -= layers * pc.R;
            }
            if (a[u]) {
                auto key = mp.begin()->L;
                mp[key] -= a[u];
                mp[key + 1] += a[u];
            }
        }
        else {
            ptr[u] = new map<LL, LL>;
            (*ptr[u])[a[u]] = 1;
            (*ptr[u])[INF] = 1;
        }
    }
    auto &mp = *ptr[0];
    mp.erase(INF);
    cout << mp.rbegin()->L << '\n';
	return 0;
}