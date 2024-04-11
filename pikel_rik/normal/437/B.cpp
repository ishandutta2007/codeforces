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
const int N = 1e6 + 5;

int visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int sum, limit;
    cin >> sum >> limit;

    vector<int> s;
    for (int i = 29; i >= 0; i--) {
        for (int j = 1; j * (ll)(1 << i) <= limit; j += 2) {
            if (sum - (1 << i) >= 0) {
                sum -= (1 << i);
                s.push_back(j * (ll)(1 << i));
            }
            else break;
        }
    }

    if (sum > 0) {
        cout << "-1\n";
        return 0;
    }

    cout << s.size() << "\n";
    for (int i : s) cout << i << " ";
    return 0;
}