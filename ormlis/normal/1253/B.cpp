#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1000001;
ll md = 1000000007;

void solve() {
    int n; cin >> n;
    vector<int> a(maxN, 0);
    vector<int> ans;
    vector<int> last(maxN, 0);
    int bad = 0, cur = 1;
    range(i, n) {
        int f; cin >> f;
        if (f < 0) {
            a[-f-1]--;
        } else {
            a[f - 1]++;
            if (last[f - 1] == cur) {
                cout << -1;
                return;
            }
            last[f - 1] = cur;
        }
        f = abs(f) - 1;
        if (a[f] > 1 || a[f] < 0) {
            cout << -1;
            return;
        }
        if (a[f]) bad++;
        else bad--;
        if (bad == 0) {ans.push_back(i); cur++;}
    }
    if (bad == 0) {
        cout << ans.size() << '\n';
        int prev = -1;
        for(auto x: ans) {
            cout << x - prev << " ";
            prev = x;
        }
    } else {
        cout << -1;
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