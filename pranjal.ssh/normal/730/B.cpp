#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) forn(i, a, (b) + 1)
#define NFOR(i, a, b) for (int i = a; i >= b; --i)

#define pb push_back
#define ff first
#define mp make_pair
#define ss second
#define all(c) c.begin(), c.end()
#define sz(a) ((int)a.size())

#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

#define foreach(c, it) for (auto it = (c).begin(); it != (c).end(); ++it)

template <class S, class T>
ostream& operator <<(ostream& os, const pair<S, T>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
void debug(T a, T b) {
    cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a) cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}

string ask(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    fflush(stdout);
    string s;
    cin >> s;
    return s;
}

int calcMin(const vi& a) {
    if (sz(a) == 1) {
        return a[0];
    }
    vi cur;
    for (int i = 0; i + 1 < sz(a); i += 2) {
        string s = ask(a[i], a[i + 1]);
        if (s == "<") {
            cur.pb(a[i]);
        } else {
            cur.pb(a[i + 1]);
        }
    }
    if (sz(a) & 1) {
        cur.pb(a.back());
    }
    return calcMin(cur);
}

int calcMax(const vi& a) {
    if (sz(a) == 1) {
        return a[0];
    }
    vi cur;
    for (int i = 0; i + 1 < sz(a); i += 2) {
        string s = ask(a[i], a[i + 1]);
        if (s == ">") {
            cur.pb(a[i]);
        } else {
            cur.pb(a[i + 1]);
        }
    }
    if (sz(a) & 1) {
        cur.pb(a.back());
    }
    return calcMax(cur);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vi a(n);
        rep (i, n) {
            a[i] = i;
        }
        vi minCands, maxCands;
        for (int i = 0; i + 1 < n; i += 2) {
            string s = ask(i + 1, i + 2);
            if (s == "<") {
                minCands.pb(i + 1);
                maxCands.pb(i + 2);
            } else {
                minCands.pb(i + 2);
                maxCands.pb(i + 1);
            }
        }
        if (n & 1) {
            minCands.pb(n);
            maxCands.pb(n);
        }
        int minIdx = calcMin(minCands);
        int maxIdx = calcMax(maxCands);
        cout << "! " << minIdx << " " << maxIdx << "\n";
        fflush(stdout);
    }
    return 0;
}