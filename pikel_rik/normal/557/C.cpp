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
const int N = 1e5 + 5;

int n, cost[201], gone[201];
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int j = 0; j < n; j++) cin >> a[j].second, cost[a[j].second]++;

    sort(a, a + n);
    int c = 1, extra = 0;

    int best = INT_MAX, sum;
    gone[a[n-1].second] += 1;
    cost[a[n-1].second] -= 1;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i].first != a[i+1].first) {
            sum = 0;
            c = i + c + 1 - (c + c - 1);

            for (int j = 1; j <= 200 && c > 0; j++) {
                if (cost[j] > c) {
                    sum += j * c;
                    c = 0;
                }
                else {
                    sum += j * cost[j];
                    c -= cost[j];
                }
            }
            best = min(best, sum + extra);

            for (int j = 1; j <= 200; j++) {
                extra += j * gone[j];
                gone[j] = 0;
            }

            c = 0;
        }

        gone[a[i].second] += 1;
        cost[a[i].second] -= 1;
        c += 1;
    }

    sum = 0;
    c = c + 1 - (c + c - 1);

    for (int j = 1; j <= 200 && c > 0; j++) {
        if (cost[j] > c) {
            sum += j * c;
            c = 0;
        }
        else {
            sum += j * cost[j];
            c -= cost[j];
        }
    }
    best = min(best, sum + extra);

    cout << best << "\n";
    return 0;
}