#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 9;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s, p;
    cin >> s >> p;

    int n = s.length(), m = p.length();
    if (m > n) {
        cout << "0\n";
        return 0;
    }

    vector<int> cnt(27), cntp(26);
    for (char c : p) cntp[c - 'a'] += 1;

    for (int i = 0; i < m; i++) {
        if (isalpha(s[i]))
            cnt[s[i] - 'a'] += 1;
        else cnt[26] += 1;
    }

    int c = m, ans = 0;
    bool flag = false;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > cntp[i]) {
            flag = true;
            break;
        }
        else {
            c -= cnt[i];
        }
    }

    flag |= (c != cnt[26]);
    if (!flag) ans += 1;

    for (int i = 1; i + m - 1 < n; i++) {
        if (isalpha(s[i-1]))
            cnt[s[i-1] - 'a'] -= 1;
        else cnt[26] -= 1;

        if (isalpha(s[i + m - 1]))
            cnt[s[i + m - 1] - 'a'] += 1;
        else cnt[26] += 1;

        c = m;
        flag = false;

        for (int j = 0; j < 26; j++) {
            if (cnt[j] > cntp[j]) {
                flag = true;
                break;
            }
            else c -= cnt[j];
        }

        flag |= (c != cnt[26]);
        if (!flag) ans += 1;
    }

    cout << ans << "\n";
    return 0;
}