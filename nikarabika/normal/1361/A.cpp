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

const int maxn = 5e5 + 10;
vector<int> adj[maxn];
int col[maxn];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        adj[se].PB(fi);
    }
    vector<pii> vec;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        num--;
        vec.PB(MP(num, i));
    }
    sort(all(vec));
    memset(col, -1, sizeof col);
    for (auto khar : vec) {
        int u = khar.R;
        bool mark[sz(adj[u]) + 1];
        memset(mark, false, sizeof mark);
        for (auto v : adj[u])
            if (col[v] != -1 and col[v] <= sz(adj[u]))
                mark[col[v]] = true;
        for (int i = 0; i < n; i++)
            if (!mark[i]) {
                col[u] = i;
                break;
            }
        if (col[u] != khar.L)
            return cout << -1 << endl, 0;
    }
    for (auto khar : vec)
        cout << khar.R + 1 << ' ';
    cout << endl;
	return 0;
}