#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <map>
#include <bitset>
#include <iomanip>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const int Nm=200001;

void solve() {
    int n, p, k; cin >> n >> p >> k;
    vector<int> arr(n);
    range(i, n) {
        cin >> arr[i];
    }
    sort(all(arr));
    vector<int> ae(k, 0);
    vector<int> aw(k, 0);
    for(int i = k - 1; i < n; ++i) {
        if (ae[i % k] + arr[i] <= p) {
            ae[i % k] += arr[i];
            aw[i % k]++;
        }
    }
    int ans = 0;
    map<int, int> a;
    a[arr[0]] = 0;
    int cur = arr[0];
    for(int i = 1; i < k - 1; ++i) {
        cur += arr[i];
        a[cur] = i;
    }
    range(i, k) {
        if (arr[0] <= p - ae[i]) {
            auto e = a.upper_bound((p - ae[i])); e--;
            ans = max(aw[i] * k + min(e->second + 1, (i + 1) % k), ans);
        } else {
            ans = max(aw[i] * k, ans);
        }
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}