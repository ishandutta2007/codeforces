#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll n; cin >> n;
    vector<int> ans = {1};
    ll need = n - 1;
    range(i, 40) {
        if (need == 0) break;
        ll addmin = ans.back();
        ll addmax = addmin * 2;
        if (need <= addmax) {
            ans.push_back(need);
            need = 0;
            break;
        }
        if (need < addmax * 2) {
            ans.push_back(need/2);
            need -= need/2;
            continue;
        }
        ans.push_back(addmax);
        need -= addmax;
    }
    cout << (int)ans.size() - 1 << '\n';
    for(int i = 1; i < (int)ans.size(); ++i) cout << ans[i] - ans[i-1] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}