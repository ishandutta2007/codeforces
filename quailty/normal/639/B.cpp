#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 100000;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, h, d;
    cin >> n >> h >> d;
    if (n == 2 && h == 1 && d == 1) {
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    if (d * 2 < h || h == 1) {
        cout << -1;
        return 0;
    }
    if (d == 1 && h == 2) {
        for (int i = 2; i <= n; i++) printf ("%d %d\n", 1, i);
        return 0;
    }
    for (int i = 1; i <= d; i++) {
        printf ("%d %d\n", i, i + 1);
    }
    for (int i = 1, j = d + 1; i <= h - d; i++, j++) {
        if (i == 1) printf ("%d %d\n", 1, j + 1);
        else printf ("%d %d\n", j, j + 1);
    }
    for (int i = h + 2; i <= n; i++) printf ("2 %d\n", i);

}