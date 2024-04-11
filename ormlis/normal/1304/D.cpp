#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 501;
ll md = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, int>> ans1(n), ans2(n);
    ans1[0] = {0, 0};
    ans2[0] = {0, 0};
    range(i, n - 1) {
        char a; cin >> a;
        if (a == '>') {
            ans1[i + 1] = {1ll * -(i + 1) * 2 * n, i + 1};
            ans2[i + 1] = {1ll * ans2[i].first - 1, i + 1};
        } else {
            ans1[i + 1] = {1ll * ans1[i].first + 1, i + 1};
            ans2[i + 1] = {1ll * (i + 1) * 2 * n, i + 1};
        }
    }
    sort(all(ans1));
    sort(all(ans2));
    vector<int> ans11(n), ans22(n);
    range(i, n) {
        ans11[ans1[i].second] = i + 1;
        ans22[ans2[i].second] = i + 1;
    }
    range(i, n) {
        cout << ans11[i] << " ";
    }
    cout << "\n";
    range(i, n) {
        cout << ans22[i] << " ";
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}