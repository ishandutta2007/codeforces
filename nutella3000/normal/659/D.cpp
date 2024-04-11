#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;

int sgn(int a) {
    if (a < 0) return -1;
    if (a > 0) return 1;
    return 0;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<int, int> a;
    a[-2] = 4;
    a[-1] = 3;
    a[1] = 1;
    a[2] = 2;

    int n;
    cin >> n;
    int res = 0;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i = 0;i < n - 2;i++) {
        int x3, y3;
        cin >> x3 >> y3;

        int r1 = sgn(x2 - x1) * 2 + sgn(y2 - y1);
        int r2 = sgn(x3 - x2) * 2 + sgn(y3 - y2);

        if (a[r2] < a[r1]) res++;

        x1 = x2;
        y1 = y2;
        x2 = x3;
        y2 = y3;
    }

    cout << res << endl;
}