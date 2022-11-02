#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

struct prosta {
    int a, b;
    prosta(int a, int b) {
        this->a = a;
        this->b = b;
    }

    bool operator < (const prosta & other) const {
        return a < other.a;
    }
};

struct ulamek {
    int n, k;
    ulamek(int n, int k) {
        if (k < 0) {
            k *= -1;
            n *= -1;
        }
        this->n = n;
        this->k = k;
    }

    bool operator < (const ulamek & other) const {
        return n*other.k < other.n*k;
    }

    bool operator > (const ulamek & other) const {
        return other < *this;
    }

    void wypisz() {
        cout << n << "/" << k << endl;
    }
};

bool prze(prosta p1, prosta p2, prosta p3) {
    ///return (p2.b-p1.b)/(p1.a-p2.a) > (p3.b-p2.b)/(p2.a-p3.a);
    ulamek u1 = {p2.b-p1.b, p1.a-p2.a};
    ulamek u2 = {p3.b-p2.b, p2.a-p3.a};
    //u1.wypisz();
    //u2.wypisz();
    return u1 < u2;
}

vector<prosta> v;
vector<prosta> oto;

map<int, int> mapa;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int x, y, i=0; i<n; i++) {
        cin >> x >> y;
        if (mapa.find(x) == mapa.end()) mapa[x] = y;
        else mapa[x] = max(mapa[x], y);
    }
    for (pair<int, int> i : mapa) {
        int x = i.first;
        int y = i.second;
        v.push_back({-x, y-x*x});
    }

    sort(v.begin(), v.end());

    //for (prosta i : v) cout << i.a << " " << i.b << endl;

    for (prosta i : v) {
        int sz=oto.size();
        while (sz>=2 && !prze(oto[sz-2], oto[sz-1], i)) {
            sz--;
            oto.pop_back();
        }
        oto.push_back(i);
    }
    cout << oto.size()-1;

    return 0;
}/*

*/