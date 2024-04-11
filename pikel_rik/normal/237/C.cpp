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

    int a, b, k;
    cin >> a >> b >> k;

    for (int i = 2; i < N; i++)
        visited[i] = 1;

    for (int i = 2; i <= 1e6; i++) {
        if (visited[i] == 1) {
            for (ll j = i * (ll)i; j <= 1e6; j += i) {
                visited[j] = 0;
            }
        }
    }

    for (int i = 1; i <= 1e6; i++)
        visited[i] += visited[i-1];

    int lo = 1, hi = b - a + 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        bool flag = true;
        for (int x = a; x <= b - mid + 1; x++) {
            flag &= (visited[x + mid - 1] - visited[x - 1] >= k);
        }

        if (flag)
            hi = mid;
        else lo = mid + 1;
    }

    bool flag = true;
    for (int x = a; x <= b - lo + 1; x++) {
        flag &= (visited[x + lo - 1] - visited[x - 1] >= k);
    }

    if (flag) cout << lo << "\n";
    else cout << "-1\n";

    return 0;
}