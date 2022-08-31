#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int k, n = s.length();
    cin >> k;

    if (k > ((ll)n * n + n) / 2) {
        cout << "No such line.\n";
        return 0;
    }

    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        a.emplace_back(s[i] - 'a', i);
    }

    string ans;
    while (k > 0) {
        vector<ll> cnt(26);
        for (auto& [ch, i] : a) {
            cnt[ch] += n - i;
        }
        int cur = -1;
        for (int i = 0; i < 26; i++) {
            if (k > cnt[i]) {
                k -= cnt[i];
            } else {
                cur = i;
                break;
            }
        }
        ans += 'a' + cur;
        vector<pair<int, int>> new_a;
        for (auto& [ch, i] : a) {
            if (ch == cur) {
                if (i + 1 < n) {
                    new_a.emplace_back(s[i + 1] - 'a', i + 1);
                }
                k--;
            }
        }
        a = new_a;
    }
    cout << ans << '\n';
    return 0;
}