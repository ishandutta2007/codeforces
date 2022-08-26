#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    if (n % 2 == 1 && k % 2 == 0) {
        cout << "NO\n";
        return;
    }
    vector<int> ans1, ans2;
    int answ1 = n, answ2 = n;
    range(i, k - 1) {
        answ1 -= 1;
        answ2 -= 2;
        ans1.push_back(1);
        ans2.push_back(2);
    }
    if (answ1 > 0 && answ1 % 2 == 1) {
        ans1.push_back(answ1);
        cout << "YES\n";
        range(i, k) cout << ans1[i] << " ";
        cout << "\n";
        return;
    }
    if (answ2 > 0 && answ2 % 2 == 0) {
        ans2.push_back(answ2);
        cout << "YES\n";
        range(i, k) cout << ans2[i] << " ";
        cout << "\n";
        return;
    }
    cout << "NO\n";
    return;
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