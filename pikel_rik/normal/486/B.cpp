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
const int N = 100;

int m, n, a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    vector<bool> vr(m), vc(n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                vr[i] = true;
                vc[j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                vr[i] = false;
                vc[j] = false;
            }
        }
    }

    bool flag = false;

    for (int i = 0; i < m && !flag; i++) {
        for (int j = 0; j < n && !flag; j++) { // !vr[0], vr[1], !vc[0], vc[1], !vc[2]
            if (a[i][j] == 1) {
                if (vr[i]) {
                    flag = true;
                    for (int k = 0; k < n; k++) {
                        flag &= (!vc[k]);
                    }
                }
                else if (vc[j]) {
                    flag = true;
                    for (int k = 0; k < m; k++) {
                        flag &= (!vr[k]);
                    }
                }
                else flag = true;
            }
        }
    }

    if (flag) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vr[i] and vc[j])
                cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}