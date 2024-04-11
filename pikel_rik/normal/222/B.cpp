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

    int n, m, k;
    cin >> n >> m >> k;

    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    vi row(n);;
    vi col(m);

    for (int i = 0; i < n; i++) row[i] = i;
    for (int j = 0; j < m; j++) col[j] = j;

    while (k--) {
        char t;
        cin >> t;

        int x, y;
        cin >> x >> y;

        x -= 1; y -= 1;
        if (t == 'g') cout << a[row[x]][col[y]] << "\n";
        else if (t == 'r') swap(row[x], row[y]);
        else swap(col[x], col[y]);
    }

    return 0;
}