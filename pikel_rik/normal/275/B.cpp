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

int n, m;
vector<string> a(50);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                for (int i1 = 0; i1 < n; i1++) {
                    for (int j1 = 0; j1 < m; j1++) {
                        if (i == i1 and j == j1) continue;
                        if (a[i1][j1] == 'W') continue;

                        if (i == i1) {
                            for (int k = min(j, j1); k <= max(j, j1); k++) {
                                if (a[i][k] != 'B') {
                                    cout << "NO\n";
                                    return 0;
                                }
                            }
                        }
                        else if (j == j1) {
                            for (int k = min(i, i1); k <= max(i, i1); k++) {
                                if (a[k][j] != 'B') {
                                    cout << "NO\n";
                                    return 0;
                                }
                            }
                        }

                        if (a[i][j1] != 'B' and a[i1][j] != 'B') {
                            cout << "NO\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "YES\n";
    return 0;
}