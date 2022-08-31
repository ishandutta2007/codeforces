#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 500001;
ll md = 1000000007;


void solve() {
    int m, n; cin >> n >> m;
    vector<int> used(n * 3, 0);
    vector<int> ans;
    range(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (!used[u] && !used[v]) {
            ans.push_back(i + 1);
            used[u] = 1;
            used[v] = 1;
        }
    }
    if (ans.size() >= n) {
        cout << "Matching\n";
        range(i, n) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "IndSet\n";
        int count = 0;
        range(i, n * 3) {
            if (count == n) break;
            if (!used[i]) {
                cout << i + 1 << " ";
                count++;
            }
        }
        cout << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}