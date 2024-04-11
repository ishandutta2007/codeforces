#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> has1(n), has2(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '.')
                has1[i] = has2[j] = true;
        }
    }

    bool ans = true, flag = true;

    for (int j = 0; j < n; j++)
        flag &= has2[j];

    for (int i = 0; i < n; i++) {
        ans &= (flag or has1[i]);
    }

    if (!ans) {
        cout << "-1\n";
        return 0;
    }

    if (!flag) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '.') {
                    cout << i + 1 << " " << j + 1 << "\n";
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j][i] == '.') {
                    cout << j + 1 << " " << i + 1 << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}