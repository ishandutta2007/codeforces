#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair

using namespace std;

mt19937 rnd(223);

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
using ll = long long;
using ld = double;

const int BIG = 1e9 + 239;

ld func(const vector<int>& e, int c) {
    int b = BIG;
    for (int i : e) {
        b = min(b, i);
    }
    return (ld)b / (ld)(c + 1);
}

int n, m;

string gett() {
    string s;
#ifdef ONPC
    s += "0";
    for (int i = 1; i < n; i++) {
        s += "1";
    }
    for (int i = 0; i < n; i++) {
        s += (rand() % 2) + '0';
    }
#else
    cin >> s;
#endif
    return s;
}

int answer(int x) {
    int a = rand() % 2;
#ifdef ONPC
    a = rand() % 2;
    //a = 0;
#else
    cout << x << endl;
    cin >> a;
#endif
    return a;
}

ld number() {
    return (rnd() % (1 << 30)) / (ld)(1 << 30);
}

int comp(ld x, ld y) {
    if (number() * (x + y) < x)
        return 0;
    return 1;
}

void solve() {
    cin >> n >> m;
    vector<int> e(n);
    int c = 0;
    for (int it = 0; it < m; it++) {
        string s = gett();
        //cin >> s;
        int go = 0;
        int mn = 1e9;
        for (int i = 0; i < n; i++)
            mn = min(mn, e[i]);
        ld x = 0, y = 0;
        auto fu = [&](int x) -> ld {
            //cerr << number() << '\n';
            //return 1 / (ld)(x - mn + 1);
            return 1 / (ld)(pow(1.5, x - mn + 1));
        };
        int cx = 0, cy = 0;
        for (int i = 0; i < n; i++) {
            if (mn == e[i]) {
                if (s[i] == '0')
                    cx++;
                else
                    cy++;
            }
            if (s[i] == '0')
                x += fu(e[i]);
            else
                y += fu(e[i]);
        }
        if (cy == 0) {
            go = 0;
        } else if (cx == 0) {
            go = 1;
        } else {
            if (comp(x, y)) {
                go = 1;
            } else {
                go = 0;
            }
        }
            if (comp(x, y)) {
                go = 1;
            } else {
                go = 0;
            }
        /*
        vector<ld> score(2);
        for (int d = 0; d < 2; d++) {
            ld bad = BIG;
            for (int a = 0; a < 2; a++) {
                vector<int> en(e);
                int cs = c;
                cs += (int)(d != a);
                for (int i = 0; i < n; i++) {
                    if (s[i] - '0' != a) {
                        en[i]++;
                    }
                }
                ld cur = func(en, cs);
                bad = min(bad, cur);
            }
            score[d] = bad;
        }*/

        int a = answer(go);
        //cout << go << endl;
        //int a;
        //cin >> a;
        c += (int)(go != a);
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != a) {
                e[i]++;
            }
        }
    }
    int b = BIG;
    for (int i : e) {
        b = min(b, i);
    }
#ifdef ONPC
    cout << 1.3 * b << " " << c << "\n";
#endif
}

int main() {
#ifdef ONPC
    freopen("../a.in", "r", stdin);
    //freopen("../a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(20);
    solve();
    cerr << "\n\nConsumed " << TIME;
}