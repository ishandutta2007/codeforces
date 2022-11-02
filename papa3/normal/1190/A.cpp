#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

//#define MAX_N 1000010

int tab[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        cin >> tab[i];
        tab[i]--;
    }

    int zmiana = 0;

    int pocz = 1, kon = 1;
    int res = 0;

    while (kon <= m) {
        pocz = kon;
        while (kon < m && (tab[pocz] - zmiana) / k == (tab[kon + 1] - zmiana) / k) {
            kon++;
        }
        kon++;
        zmiana += kon - pocz;
        res++;
    }

    cout << res;

    return 0;
}
/*

*/