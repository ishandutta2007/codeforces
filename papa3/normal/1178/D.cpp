#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 998244353ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int sito[MAX_N];

void init() {
    sito[1] = 1;
    for (int i = 2; i <= 10000; i++) {
        if (sito[i]) continue;
        for (int j = 2 * i; j <= 10000; j += i) {
            sito[j] = i;
        }
    }
}

bool wynik(int n) {
    vector<pair<int, int> > res;
    for (int i = 1; i < n; i++) {
        res.push_back({i, i + 1});
    }
    res.push_back({1, n});

    int ile = n;
    while (sito[ile]) ile++;

    int suma = n;

    int pocz = 1, kon = n - 1;
    while (suma < ile) {
        while (n > 2 && (sito[n] || suma + n - 2 > ile)) n--;
        if (n == 2) return false;
        for (int i = 0; i < n - 2; i++) {
            if (kon - pocz < 2) return false;
            res.push_back({pocz, kon--});
        }
        suma += n - 2;
        pocz++;
    }

    cout << res.size() << "\n";
    for (pair<int, int> i : res) {
        cout << i.first << " " << i.second << "\n";
    }

    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n;
    cin >> n;
    wynik(n);


    return 0;
}
/*

*/