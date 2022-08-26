#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ab, oa, ob, nab;
    range(i, n) {
        int t;
        cin >> t;
        int a, b;
        cin >> a >> b;
        if (a && b) ab.push_back(t);
        else if (a) oa.push_back(t);
        else if (b) ob.push_back(t);
        else nab.push_back(t);
    }
    sort(all(ab));
    sort(all(ob));
    sort(all(oa));
    ll ans = 0;
    int cnt1 = min(k, (int) oa.size());
    int cnt2 = min(k, (int) ob.size());
    range(i, cnt1) ans += oa[i];
    range(i, cnt2) ans += ob[i];
    int cnt3 = 0;
    range(i, (int) ab.size()) {
        bool u = false;
        if (cnt1 + cnt3 < k || cnt2 + cnt3 < k) {
            u = true;
        }
        if (cnt1 != 0 && oa[cnt1 - 1] > ab[i]) {
            u = true;
        }
        if (cnt2 != 0 && ob[cnt2 - 1] > ab[i]) {
            u = true;
        }
        if (cnt1 != 0 && cnt2 != 0 && oa[cnt1 - 1] + ob[cnt2 - 1] > ab[i]) {
            u = true;
        }
        if (u) {
            ans += ab[i];
            cnt3++;
        }
        while (cnt1 > 0 && cnt1 + cnt3 > k) {
            ans -= oa[cnt1 - 1];
            cnt1--;
        }

        while (cnt2 > 0 && cnt2 + cnt3 > k) {
            ans -= ob[cnt2 - 1];
            cnt2--;
        }
    }
    if (cnt1 + cnt3 < k || cnt2 + cnt3 < k) {
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}