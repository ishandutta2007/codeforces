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
const int N = 1e5 + 5;

int n, k;
vector<int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int sz; cin >> sz;
        a[i].resize(sz);
        for (int j = 0; j < sz; j++)
            cin >> a[i][j];
    }

    int best = 0;
    for (int i = 0; i < k; i++) {
        int cur = 0, next = 1;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == next)
                cur++, next++;
            else break;
        }
        best = max(best, cur);
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (a[i].front() == 1)
            sum += a[i].size() - best;
        else sum += a[i].size() - 1;
    }

    cout << n - best + sum << "\n";
    return 0;
}