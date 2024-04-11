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

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> s;
        n = s.length();

        vector<int> cnt(10);
        for (char ch : s) cnt[ch - '0']++;

        int best = n - *max_element(all(cnt));

        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (!cnt[i] or !cnt[j]) continue;

                string temp;
                for (char ch : s) {
                    if (ch - '0' == i or ch - '0' == j)
                        temp.push_back(ch);
                }

                int c = 1;
                for (int j = 1; j < temp.size(); j++) {
                    if (temp[j] != temp[j - 1])
                        c++;
                }

                best = min(best, n - c + (c & 1));
            }
        }

        cout << best << "\n";
    }
    return 0;
}