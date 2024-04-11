#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 998244353ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

struct moj {
    int kolor, koniec;
    int poz;
};

moj tab[1000];
int dp[1000][1000];

int daj(int pocz, int kon) {
    if (pocz >= kon) return 1;
    if (dp[pocz][kon] != -1) return dp[pocz][kon];

    moj x = tab[pocz];
    for (int i = pocz; i < kon; i++) {
        if (x.kolor > tab[i].kolor) x = tab[i];
    }

    int lewa = 0;
    for (int i = pocz; i <= x.poz; i++) {
        lewa = (lewa + daj(pocz, i) * daj(i, x.poz)) % mod;
    }

    int prawa = 0;
    for (int i = x.koniec; i <= kon; i++) {
        prawa = (prawa + daj(x.koniec, i) * daj(i, kon)) % mod;
    }

    return dp[pocz][kon] = lewa * prawa % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + 10; i++) {
        for (int j = 0; j < n + 10; j++) {
            dp[i][j] = -1;
        }
    }

    for (int a, i = 1; i <= m; i++) {
        cin >> a;
        tab[i].kolor = a;
        tab[i].poz = i;
        tab[i].koniec = i + 1;
    }

    cout << daj(1, m + 1);

    return 0;
}
/*

*/