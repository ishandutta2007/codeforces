#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int n, h;
int tab[1000010];

bool algo(int kon) {
    vector<int> v;
    for (int i=1; i<=kon; i++) {
        v.push_back(tab[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int wys=0;
    for (int i=0; i<v.size(); i+=2) {
        wys += v[i];
    }
    return wys <= h;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    for (int i=1; i<=n; i++) {
        cin >> tab[i];
    }

    int pocz = 0, kon=n+1, sr=0;

    while (kon-pocz > 1) {
        sr = (pocz + kon) /2;
        if (algo(sr)) pocz = sr;
        else kon = sr;
    }
    cout << pocz;

    return 0;
}/*

*/