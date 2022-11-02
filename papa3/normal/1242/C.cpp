#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define cerr if (true) {} else cout
#define pisz(x) #x << ": " << x

int tab[100];
map<int, int> mapa;

struct moj {
    int a;
    int inside;
    int dokad;
    int ile_w;
    int id;
    bool visited;

    moj(int a, int inside, int id) {
        this->a = a;
        this->inside = inside;
        this->id = id;
        dokad = -1;
        ile_w = 0;
        visited = false;
    }
};

struct ccc {
    int inside, a;
};

struct cykl {
    int maska;
    vector<ccc> data;
    int id;

    cykl(int id) {
        this->id = id;
        maska = 0;
    }

    bool operator < (const cykl &other) const {
        return maska < other.maska;
    }
};

vector<moj> v;
vector<cykl> cykle;

int dp[1000010];
pair<int, int> res[100000];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    int sum = 0;
    v.push_back({-1, -1, -1});
    for (int a, n, i = 0; i < k; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> a;
            mapa[a] = v.size();
            v.push_back({a, i, v.size()});
            sum += a;
            tab[i] += a;
        }
    }

    int ocz = sum / k;
    if (ocz * k != sum) {
        cout << "No";
        return 0;
    }
    cerr << ocz << endl;

    for (moj &i : v) {
        if (i.id == -1) continue;
        int dokad = ocz - (tab[i.inside] - i.a);
        if (mapa[dokad]) {
            int x = mapa[dokad];
            if (i.a != dokad && i.inside == v[x].inside) continue;
            i.dokad = x;
            v[x].ile_w++;
        }
    }

    queue<int> kol;
    for (moj &i : v) {
        if (i.id == -1) continue;
        if (i.ile_w == 0) kol.push(i.id);
    }

    while (!kol.empty()) {
        int gdzie = kol.front();
        kol.pop();

        int d = v[gdzie].dokad;
        if (d != -1) {
            if (--v[d].ile_w == 0) {
                kol.push(v[d].id);
            }
        }
    }

    for (int i = 1; i < v.size(); i++) {
        if (!v[i].visited && v[i].ile_w > 0) {
            cykle.push_back({cykle.size()});
            int gdzie = i;
            cerr << "cykl" << endl;
            set<int> s;
            do {
                cerr << pisz(v[gdzie].inside + 1) << " " << pisz(v[gdzie].a) << endl;
                cykle.back().data.push_back({v[gdzie].inside + 1, v[gdzie].a});
                if (s.find(v[gdzie].inside) != s.end()) {
                    cykle.pop_back();
                    break;
                } else {
                    s.insert(v[gdzie].inside);
                }
                cykle.back().maska |= (1 << v[gdzie].inside);
                v[gdzie].visited = true;
                gdzie = v[gdzie].dokad;
            } while (gdzie != i);
        }
    }

    set<cykl> sss(cykle.begin(), cykle.end());
    for (int mask = 1; mask < (1 << k); mask++) {
        dp[mask] = -1;
        for (const cykl &i : sss) {
            if ((mask & i.maska) == i.maska && dp[mask ^ i.maska] != -1) {
                dp[mask] = i.id;
                cerr << mask << " " << dp[mask] << " " << i.maska << " " << (mask ^ i.maska) << endl;
                break;
            }
        }
    }
    cerr << "koniec" << endl;

    int gdzie = (1 << k) - 1;
    if (dp[gdzie] == -1) {
        cout << "No";
        return 0;
    }

    //int li = 10;
    while (gdzie) {
        auto &c = cykle[dp[gdzie]];
        cerr << gdzie << endl;
        reverse(c.data.begin(), c.data.end());
        for (int i = 0; i < c.data.size(); i++) {
            res[c.data[i].inside] = {c.data[i].a, c.data[(i + 1) % c.data.size()].inside};
        }
        gdzie ^= c.maska;
    }

    cout << "Yes\n";
    for (int i = 1; i <= k; i++) {
        cout << res[i].first << " " << res[i].second << "\n";
    }

    return 0;
}
/*

*/