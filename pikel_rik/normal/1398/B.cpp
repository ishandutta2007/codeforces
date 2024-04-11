#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int len = 0;
        vector<int> v;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0' and len) {
                v.push_back(len);
                len = 0;
            }
            else if (s[i] == '1')
                len++;
        }

        if (len)
            v.push_back(len);
        sort(all(v), greater<>());

        int score = 0;
        for (int i = 0; i < v.size(); i += 2)
            score += v[i];

        cout << score << "\n";
    }
    return 0;
}