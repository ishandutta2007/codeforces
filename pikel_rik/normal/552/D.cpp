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
const int N = 2e3 + 5;

int n;
vector<pair<int, int>> points;

bool visited[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        x += 100; y += 100;
        points.emplace_back(x, y);
        visited[x][y] = true;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int y1 = points[i].second;
        int x1 = points[i].first;

        for (int j = i + 1; j < n; j++) {
            int c = 0;
            int slopey = points[j].second - points[i].second, slopex = points[j].first - points[i].first;
            int g = __gcd(slopey, slopex);

            slopey /= g;
            slopex /= g;

            if (slopex == 0) {
                for (int y = 0; y <= 200; y++) {
                    if (y >= 0 and y <= 200 and visited[x1][y])
                        c += 1;
                }
            }
            else {
                for (int x = 0; x <= 200; x++) {
                    if ((x - x1) % slopex != 0)
                        continue;

                    int y = y1 + slopey * (x - x1) / slopex;
                    if (x >= 0 and x <= 200 and y >= 0 and y <= 200 and visited[x][y])
                        c += 1;
                }
            }

            ans += n - c;
        }
    }

    cout << ans / 3 << "\n";
    return 0;
}