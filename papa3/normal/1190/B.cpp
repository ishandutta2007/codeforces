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

    bool nieZero = false;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
        if (tab[i]) {
            nieZero = true;
        }
    }

    sort(tab, tab + n);

    if (!nieZero) {
        cout << "cslnb";
        return 0;
    }

    if (n > 1 && tab[1] == 0) {
        cout << "cslnb";
        return 0;
    }

    int pary = 0;
    for (int i = 1; i < n; i++) {
        if (tab[i] == tab[i - 1]) {
            pary++;
            if (pary > 1 || i >= 2 && tab[i - 2] == tab[i] - 1) {
                cout << "cslnb";
                return 0;
            }
        }
    }

    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += tab[i] - i;
    }

    if (suma % 2 == 0) {
        cout << "cslnb";
    } else {
        cout << "sjfnb";
    }

    return 0;
}
/*

*/