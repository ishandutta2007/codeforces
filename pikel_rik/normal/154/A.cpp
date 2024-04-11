#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int n, k, f[26];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s >> k;
    n = s.length();
    memset(f, -1, sizeof(f));

    for (int i = 0; i < k; i++) {
        string temp;
        cin >> temp;

        f[temp[0] - 'a'] = temp[1] - 'a';
        f[temp[1] - 'a'] = temp[0] - 'a';
    }

    vector<pair<int, int>> a;

    int len = 1, cur = s[0] - 'a';
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            a.emplace_back(len, cur);
            len = 0;
            cur = s[i] - 'a';
        }
        len++;
    }
    a.emplace_back(len, cur);

//    for (auto p : a) cout << p.first << " " << p.second << "\n";

    int ans = 0, len1 = a[0].first, len2 = 0, sit = 1;
    cur = a[0].second;

    for (int i = 1; i < a.size(); i++) {
        if (a[i].second == f[cur]) {
            cur = a[i].second;
            if (sit) len2 += a[i].first;
            else len1 += a[i].first;

            sit = 1 - sit;
        }
        else {
            ans += min(len1, len2);
            len1 = a[i].first;
            len2 = 0;
            sit = 1;

            cur = a[i].second;
        }
    }

    ans += min(len1, len2);

    cout << ans << "\n";
    return 0;
}