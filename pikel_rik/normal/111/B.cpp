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

int visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int t = 1; t <= n; t++) {
        int x, y;
        cin >> x >> y;

        if (y == 0) y = t;
        else y = t - y;

        int c = 0;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (visited[i] < y)
                    c += 1;
                if (x / i != i and visited[x / i] < y)
                    c += 1;
                visited[i] = visited[x / i] = t;
            }
        }

        cout << c << "\n";
    }
    return 0;
}