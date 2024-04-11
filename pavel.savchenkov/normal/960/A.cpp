#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

string s;

bool read() {
    if  (!(getline(cin, s))) {
        return 0;
    }
    return 1;
}

bool solve() {
    int a = 0;
    int i = 0;
    while (i < sz(s) && s[i] == 'a') {
        ++i;
        ++a;
    }
    if  (!a) {
        return 0;
    }
    int b = 0;
    while (i < sz(s) && s[i] == 'b') {
        ++i;
        ++b;
    }
    if  (!b) {
        return 0;
    }
    int c = 0;
    while (i < sz(s) && s[i] == 'c') {
        ++i;
        ++c;
    }
    if  (i != sz(s)) {
        return 0;
    }
    if  (c != a && c != b)  {
        return 0;
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        cout << (solve() ? "YES" : "NO") << endl;;
    }

    return 0;
}