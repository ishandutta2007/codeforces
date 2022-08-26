#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 41;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    bool flag = false;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && s[i] == s[j]) j++;
        int len = j - i;
        int c = s[i] - '0';
        if (c) {
            if (len == 1 && !flag) ans++;
            else if (!flag) {
                flag = true;
                ans += 2;
            }
        } else {
            if (len >= 2) flag = false;
            else if (flag && j != n) ans++;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}