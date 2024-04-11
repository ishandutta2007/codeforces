#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int per[1000010];
int tab[1000010];
int pos[1000010];
int nas[20][1000010];
int wy[1000010];

void policz( int gdzie ) {
    for (int i=1; i<20; i++) {
        nas[i][gdzie] = nas[i-1][ nas[i-1][gdzie] ];
    }
}

int n;

int skocz(int gdzie) {
    int ile=n-1;
    for (int i=19; i>=0; i--) {
        if ((1<<i) <= ile) {
            gdzie = nas[i][gdzie];
            ile -= (1<<i);
        }
    }
    if (gdzie == 0) return INF;
    return gdzie;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, q;
    cin >> n >> m >> q;

    for (int a, i=1; i<=n; i++) {
        cin >> a;
        per[a] = i;
    }
    for (int i=1; i<=m; i++) {
        cin >> tab[i];
        tab[i] = per[tab[i]]-1;
        //cout << tab[i] << " ";
    }

    for (int i=m; i>0; i--) {
        nas[0][i] = pos[(tab[i]+1)%n];
        pos[tab[i]] = i;
        policz(i);
        wy[i] = skocz(i);
    }

    for (int i=m-1; i>0; i--) {
        wy[i] = min(wy[i], wy[i+1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (wy[l] <= r) cout << 1;
        else cout << 0;
    }


    /*cout << endl;
    for (int i=1; i<=m; i++) {
        cout << nas[i] << " ";
    }
    cout << endl;
    for (int i=1; i<=m; i++) {
        cout << wy[i] << " ";
    }*/

    /*while (q--) {
        int l, r;
        cin >> l >> r;
        if (wy[l] <= r) cout << 1;
        else cout << 0;
    }*/

    return 0;
}/*

*/