#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

//#define MAX_N 1000010

const int baza = 1 << 20;
int drz[baza * 2];

void akt(int gdzie) {
    gdzie += baza;
    if (drz[gdzie]) return;
    while (gdzie) {
        drz[gdzie]++;
        gdzie /= 2;
    }
}

int czytaj(int pyt_pocz, int pyt_kon, int pocz = 0, int kon = baza, int gdzie = 1) {
    if (pyt_pocz > pyt_kon) swap(pyt_pocz, pyt_kon);

    if (pyt_pocz <= pocz && kon <= pyt_kon) {
        return drz[gdzie];
    }

    if (pyt_kon <= pocz || kon <= pyt_pocz) {
        return 0;
    }

    int sr = (pocz + kon) / 2;
    return  czytaj(pyt_pocz, pyt_kon, pocz, sr, gdzie * 2) +
            czytaj(pyt_pocz, pyt_kon, sr, kon, gdzie * 2 + 1);
}

map<int, int> mapa;
vector<pair<int, int> > v;
set<int> s;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int a, b, i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({b, a});
        s.insert(a);
        s.insert(b);
    }

    int li = 1;
    for (int i : s) {
        mapa[i] = li++;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (pair<int, int> & i : v) {
        swap(i.first, i.second);
        i.first = mapa[i.first];
        i.second = mapa[i.second];
        //cout << i.first << " " << i.second << endl;
    }

    int res = 0;

    int pocz = 0, kon = 0;
    while (kon < n) {
        pocz = kon;
        while (kon < n && v[kon].second == v[pocz].second) {
            akt(v[kon].first);
            kon++;
        }

        res += drz[1] * (drz[1] + 1) / 2;

        for (int x, i = pocz; i + 1 < kon; i++) {
            x = czytaj(v[i + 1].first, v[i].first) - 1;
            res -= x * (x + 1) / 2;
        }

        int x = czytaj(0, v[kon - 1].first);
        res -= x * (x + 1) / 2;

        x = czytaj(v[pocz].first, baza) - 1;
        res -= x * (x + 1) / 2;
        //cout << res << endl;
    }

    cout << res;

    return 0;
}
/*
7
1 1
2 2
4 1
1 2
3 2
0 2
4 2
*/