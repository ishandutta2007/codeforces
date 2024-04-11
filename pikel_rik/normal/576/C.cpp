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

struct point {
    int x, y;
    explicit point(int x = 0, int y = 0): x(x), y(y) {}
};

const int N = 1e6 + 5;
const int nN = 1767 + 4;

int n;
point a[N];

vector<int> groups[nN][nN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        groups[a[i].x / 1767][a[i].y / 1767].push_back(i + 1);
    }

    //1767 * 1767

    vector<int> ans;
    for (int i = 0; i < nN; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < nN; j++) {
                if (groups[i][j].empty()) continue;

                sort(all(groups[i][j]), [&](int i, int j) {
                    if (a[i].x != a[j].x)
                        return a[i].x < a[j].x;
                    return a[i].y < a[j].y;
                });

                int last = 0, c = 1;
                for (int k = 1; k < groups[i][j].size(); k++) {
                    int idx1 = groups[i][j][k], idx2 = groups[i][j][k - 1];
                    if (a[idx1].x != a[idx2].x) {
                        if (c % 2 == 0)
                            reverse(groups[i][j].begin() + last, groups[i][j].begin() + k);
                        last = k;
                        c++;
                    }
                }
                if (c % 2 == 0)
                    reverse(groups[i][j].begin() + last, groups[i][j].end());

                for (int k : groups[i][j])
                    ans.push_back(k);
            }
        }
        else {
            for (int j = nN - 1; j >= 0; j--) {
                if (groups[i][j].empty()) continue;

                sort(all(groups[i][j]), [&](int i, int j) {
                    if (a[i].x != a[j].x)
                        return a[i].x > a[j].x;
                    return a[i].y < a[j].y;
                });

                int last = 0, c = 1;
                for (int k = 1; k < groups[i][j].size(); k++) {
                    int idx1 = groups[i][j][k], idx2 = groups[i][j][k - 1];
                    if (a[idx1].x != a[idx2].x) {
                        if (c % 2 == 0)
                            reverse(groups[i][j].begin() + last, groups[i][j].begin() + k);
                        last = k;
                        c++;
                    }
                }
                if (c % 2 == 0)
                    reverse(groups[i][j].begin() + last, groups[i][j].end());

                for (int k : groups[i][j])
                    ans.push_back(k);
            }
        }
    }

    for (int i : ans) cout << i << " "; cout << "\n";
    return 0;
}