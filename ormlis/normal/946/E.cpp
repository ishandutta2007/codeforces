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
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    bool flag = (s[0] == '1') && (s[n - 1] == '1' || s[n - 1] == '0');
    for (int i = 1; i < n - 1; ++i) if (s[i] != '0') flag = false;

    if (n % 2 == 1 || flag) {
        range(i, (n - 1) / 2 * 2) cout << '9';
        cout << "\n";
        return;
    }

    map<char, int> cnt;
    range(i, n) cnt[s[i]]++;
    for (int i = n - 1; i >= 0; --i) {
        cnt[s[i]]--;
        if (s[i] == '0') {
            s[i] = '9';
            continue;
        }
        s[i]--;
        vector<char> need;
        for (char a = '0'; a <= '9'; ++a) if (cnt[a] % 2) need.push_back(a);
        if (need.size() > n - i || (need.size() == n - i && need[0] > s[i])) {
            s[i] = '9';
            continue;
        }
        cout << s.substr(0, i);
        if (need.size() == n - i) {
            for (int j = i; j < n; ++j) {
                for (int e = (int) need.size() - 1; e >= 0; --e) {
                    if (need[e] <= s[j]) {
                        cout << need[e];
                        need.erase(need.begin() + e);
                        break;
                    }
                }
            }
            break;
        }
        need.clear();
        cnt[s[i]]++;
        for (char a = '0'; a <= '9'; ++a) if (cnt[a] % 2) need.push_back(a);
        for (int j = i; j < n - need.size(); ++j) cout << s[j];
        for (int j = n - (int) need.size(); j < n; ++j) {
            for (int e = (int) need.size() - 1; e >= 0; --e) {
                if (need[e] <= s[j]) {
                    cout << need[e];
                    need.erase(need.begin() + e);
                    break;
                }
            }
        }
        break;
    }
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