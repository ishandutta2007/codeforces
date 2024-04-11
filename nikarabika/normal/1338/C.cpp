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

LL midmap[4] = {0, 2, 3, 1};
LL rimap[4] = {0, 3, 1, 2};

LL trans(LL x, LL map[]) {
    LL y = 0;
    LL pos = 0;
    while (x) {
        LL cur = x & 3;
        cur = map[cur];
        y |= cur << pos;
        pos += 2;
        x >>= 2;
    }
    return y;
}

int solve() {
    LL n;
    cin >> n;
    n--;
    LL row = n / 3,
       col = n % 3;
    LL pos = 0;
    {
        while (row >= (1LL << pos)) {
            row -= 1LL << pos;
            pos += 2;
        }
    }
    if (col == 0)
        cout << row + (1LL << pos) << '\n';
    else if (col == 1)
        cout << trans(row, midmap) + (2LL << pos) << '\n';
    else
        cout << trans(row, rimap) + (3LL << pos) << '\n';
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}