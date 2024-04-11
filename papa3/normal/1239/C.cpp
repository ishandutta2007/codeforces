#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int tab[MAX_N];

struct moj {
    int t;
    int id;
    bool dod;

    bool operator < (const moj & other) const {
        if (t == other.t) {
            if (dod == other.dod) {
                return id < other.id;
            }

            return dod > other.dod;
        }

        return t < other.t;
    }
};

int res[MAX_N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    set<moj> kol;

    for (int a, i = 0; i < n; i++) {
        cin >> a;
        kol.insert({a, i, true});
    }

    set<int> w_kolejce;
    w_kolejce.insert(INF);
    set<int> czeka;
    //czeka.insert(INF);
    int koniec = -1;

    while (!kol.empty()) {
        moj x = *kol.begin();
        kol.erase(kol.begin());

        if (x.dod) {
            if (*w_kolejce.begin() > x.id) {
                w_kolejce.insert(x.id);
                koniec = max(x.t, koniec) + p;
                kol.insert({koniec, x.id, false});
                res[x.id] = koniec;
            } else {
                czeka.insert(x.id);
            }
        } else {
            w_kolejce.erase(x.id);

            if (!czeka.empty() && *czeka.begin() < *w_kolejce.begin()) {
                int a = *czeka.begin();
                czeka.erase(czeka.begin());

                koniec = koniec + p;
                w_kolejce.insert(a);
                kol.insert({koniec, a, false});
                res[a] = koniec;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}
/*

*/