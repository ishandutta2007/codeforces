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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set < pair <ll, ll> > ranges;
    ranges.insert({1ll, 1e18});
    rep (i, n) {
        ll s, d;
        cin >> s >> d;

        pair <ll, ll> cur(-1, -1);
        for (const auto& p : ranges) {
            if (p.ff <= s and s <= p.ss) {
                cur = p;
                break;
            }
        }
        if (cur.ff != -1 and cur.ss - s + 1 >= d) {
            cout << s << " " << s + d - 1 << "\n";
            ranges.erase(cur);
            if (cur.ff <= s - 1) {
                ranges.insert({cur.ff, s - 1});
            }
            if (s + d <= cur.ss) {
                ranges.insert({s + d, cur.ss});
            }
        } else {
            cur = {-1, -1};
            for (const auto& p : ranges) {
                if (p.ss - p.ff + 1 >= d) {
                    cur = p;
                    break;     
                }
            }
            assert(cur.ff != -1);
            cout << cur.ff << " " << cur.ff + d - 1 << "\n";
            ranges.erase(cur);
            if (cur.ff + d <= cur.ss) {
                ranges.insert({cur.ff + d, cur.ss});
            }
        }
    }
    return 0;
}