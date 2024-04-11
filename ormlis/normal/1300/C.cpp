#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e5 * 2;
ll md = 1000000007;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int> (33, 0));
    vector<int> b(33, 0);
    vector<int> s(n);
    range(i, n) {
        int f; cin >> f;
        s[i] = f;
        range(j, 33) {
            a[i][j] += f % 2;
            b[j] += f % 2;
            f /= 2;
        }
    }
    int ans = 0, ansi = 0;
    range(i, n) {
        int cur = 0;
        range(j, 33) {
            if (b[j] == 1 && a[i][j] == 1) {
                cur += 1 << j;
            }
        }
        if (ans < cur) ansi = i;
        ans = max(ans, cur);
    }
    cout << s[ansi] << " ";
    range(i, n) {
        if (i == ansi) continue;
        cout << s[i] << " ";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}