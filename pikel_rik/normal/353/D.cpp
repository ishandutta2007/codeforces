#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e6 + 5;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    n = s.length();

    int last = -1, lastc = -1, ans = -1, c = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'F' and last == -1) {
            lastc = last = ans = i;
            c = 1;
            continue;
        }

        if (s[i] == 'F') {
            int dist = i - last - 1, time = last - (c - 1);

            if (lastc - time >= dist and i != c)
                lastc = 1 + lastc - time + last - (c - 1);
            else lastc = i - c;

            ans = max(ans, lastc);
            last = i;
            c += 1;
        }
    }

    if (ans == -1) cout << "0\n";
    else cout << ans << "\n";
    return 0;
}