#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vvi a(n, vi(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    vector<vector<ll>> main(n, vector<ll>(n)), anti(n, vector<ll>(n));

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) main[i][j] = anti[i][j] = a[i][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            main[i][j] += main[i-1][j-1];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            anti[i][j] += anti[i-1][j+1];
        }
    }

    pi best_1 = {-1, -1}, best_2 = {-1, -1};
    ll best_val1 = INT_MIN, best_val2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll val = 0;

            if (j + n - i - 1 > n - 1)
                val += main[i + n - j - 1][n-1];
            else val += main[n-1][j + n - i - 1];

            if (j - n + i + 1 < 0)
                val += anti[i + j][0];
            else val += anti[n-1][j - n + i + 1];

            val -= a[i][j];

            if ((i + j) % 2 == 0 and val > best_val1) {
                best_val1 = val;
                best_1 = {i, j};
            }
            else if ((i + j) % 2 != 0 and val > best_val2) {
                best_val2 = val;
                best_2 = {i, j};
            }
        }
    }

    cout << best_val1 + best_val2 << "\n";
    cout << best_1.first + 1 << " " << best_1.second + 1 << " " << best_2.first + 1 << " " << best_2.second + 1 << "\n";
    return 0;
}