#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);


const int inf = 1e9 + 7;
const int max_n = 4e5 + 3;

set<int> gr[max_n];
vector<int> bad;
int n, k;

void run() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        gr[i].clear();
    bad.clear();
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2; --v1, --v2;
        gr[v1].insert(v2);
        gr[v2].insert(v1);
    }
    for (int i = 0; i < n; ++i) {
        if (size(gr[i]) == 1) bad.pb(i);
    }
    int res = n;
    for (int it = 0; it < k; ++it) {
        if (res == 1) {
            res = 0;
        }
        if (res == 0) break;
        vector<int> nb;
        res -= size(bad);
        for (int i : bad) {
            for (int j : gr[i]) {
                gr[j].erase(i);
                if (size(gr[j]) == 1)
                    nb.pb(j);
            }
        }
        swap(nb, bad);
    }
    cout << max(0ll, res) << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        run();
    }
}