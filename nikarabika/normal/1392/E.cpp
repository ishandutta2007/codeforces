//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    LL a[n][n];
    for (int s = 0; s < n + n - 1; s++) {
        for (int i = 0; i < n; i++) {
            int j = s - i;
            if (j < 0 or j >= n)
                continue;
            a[i][j] = (i & 1) * (1LL << s);
        }
    }
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
    int q;
    cin >> q;
    while (q--) {
        LL num;
        cin >> num;
        int x = 0,
            y = 0;
        while (x != n - 1 or y != n - 1) {
            cout << x + 1 << ' ' << y + 1 << '\n';
            if (x == n - 1)
                y++;
            else if (y == n - 1)
                x++;
            else if (a[x + 1][y]) {
                if (a[x + 1][y] & num)
                    x++;
                else
                    y++;
            }
            else if (a[x][y + 1]) {
                if (a[x][y + 1] & num)
                    y++;
                else
                    x++;
            }
        }
        cout << x + 1 << ' ' << y + 1 << endl;
    }
	return 0;
}