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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        sort(all(cnt), greater<>());

        for (int i = n; i >= 1; i--) {
            vector<bool> visited(i);
            vector<int> lens, cnt1(cnt);

            for (int j = 0; j < i; j++) {
                if (!visited[j]) {
                    int len = 0, cur = j;
                    while (!visited[cur]) {
                        visited[cur] = true;
                        cur = (cur + k) % i;
                        len++;
                    }
                    lens.push_back(len);
                }
            }

            sort(all(lens), greater<>());

            bool ok = true;
            for (int j : lens) {
                if (j > cnt1.front())
                    ok = false;
                else {
                    cnt1.front() -= j;
                    sort(all(cnt1), greater<>());
                }
            }

            if (ok) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}