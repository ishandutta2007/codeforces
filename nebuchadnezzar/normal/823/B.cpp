/**
  *  Team Eat Less - Drink More
  */
#ifdef LOCAL
//#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>

#define szof(a) ((int)(a).size())
#define bend(a) a.begin(), a.end()
#define ff first
#define ss second
#define puba push_back

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

int millis() { static auto start = chrono::system_clock::now(); return 1e3 * chrono::duration<double>(chrono::system_clock::now() - start).count(); }

int const N = 100100;
int const LEN = 11;

int fenw[LEN][LEN][4][N];

void add(int mod, int rem, int x, int pos, int val) {
    for (++pos; pos < N; pos += pos & -pos) {
        fenw[mod][rem][x][pos] += val;
    }
}

int get_sum(int mod, int rem, int x, int from, int to) {
    int ret = 0;
    for (; to > 0; to &= to - 1) {
        ret += fenw[mod][rem][x][to];
    }
    for (; from > 0; from &= from - 1) {
        ret -= fenw[mod][rem][x][from];
    }
    return ret;
}

void solve() {
    static char s[N];
    scanf("%s", s);
    int n = strlen(s);
    static int a[N];
    
    static int code[333];
    memset(code, -1, sizeof(code));
    code['A'] = 0, code['T'] = 1, code['C'] = 2, code['G'] = 3;
    
    for (int i = 0; i < n; ++i) {
        a[i] = code[s[i]];
    }
    
    for (int len = 1; len < LEN; ++len) {
        for (int i = 0; i < n; ++i) {
            add(len, i % len, a[i], i, 1);
        }
    }
    
    int q;
    scanf("%d", &q);
    for (int it = 0; it < q; ++it) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int pos;
            char ch;
            scanf("%d %c", &pos, &ch);
            --pos;
            int x = code[ch];
            for (int len = 1; len < LEN; ++len) {
                add(len, pos % len, a[pos], pos, -1);
                add(len, pos % len, x, pos, 1);
            }
            a[pos] = x;
        } else {
            int l, r;
            static char e[111];
            scanf("%d%d%s", &l, &r, e);
            --l;
            int len = strlen(e);
            int ans = 0;
            for (int i = 0; i < len && l + i < r; ++i) {
                int x = code[e[i]];
                ans += get_sum(len, (l + i) % len, x, l, r);
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    millis();
    cout << setprecision(15) << fixed;
#ifdef LOCAL
    cerr << setprecision(4) << fixed;
#endif
    int tests = 1;
    for (int test = 1; test <= tests; ++test) {
        solve();
    }
#ifdef LOCAL
    cerr << "time: " << millis() << " ms\n";
#endif
}