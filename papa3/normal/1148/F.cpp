#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

pair<int, int> tab[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tab[i].first >> tab[i].second;
        res += tab[i].first;
    }

    if (res < 0) {
        for (int i = 1; i <= n; i++) {
            tab[i].first *= -1;
        }
        res *= -1;
    }

    int mask = 0;
    int anti = (1ll<<63)-1;

    for (int i = 0; ; i++) {
        mask ^= (1ll<<i);
        anti ^= (1ll<<i);
        int suma = 0;
        for (int j = 1; j <= n; j++) {
            if (!(tab[j].second & anti) && tab[j].second & (1ll<<i)) {
                suma += tab[j].first;
            }
        }
        if (suma > 0) {
            for (int j = 1; j <= n; j++) {
                if (tab[j].second & (1ll<<i)) {
                    tab[j].first *= -1;
                    res += 2*tab[j].first;
                }
            }
        } else {
            mask ^= (1ll<<i);
        }

        if (res < 0) {
            cout << mask;
            return 0;
        }
    }

    return 0;
}
/*

*/