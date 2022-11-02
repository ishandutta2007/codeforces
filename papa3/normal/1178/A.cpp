#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int tab[MAX_N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> res;
    int n;
    cin >> n;
    int suma = 0, wy = 0;
    int al;
    for (int a, i = 1; i <= n; i++) {
        cin >> a;
        if (i == 1) {
            al = a;
            wy += a;
            res.push_back(1);
        }

        if (al >= 2 * a) {
            res.push_back(i);
            wy += a;
        }

        suma += a;
    }

    if (suma < 2 * wy) {
        cout << res.size() << "\n";
        for (int i : res) {
            cout << i << " ";
        }
    } else {
        cout << 0;
    }

    return 0;
}
/*

*/