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
#include <numeric>
#include <functional>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <bitset>

using namespace std;

#define prev prev_______________________
#define next next_______________________
#define hash hash_______________________
#define y1 y1___________________________

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#define cerr if (0) cerr
#endif

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int dims[3];

bool read() {
    if  (!(cin >> dims[0])) {
        return 0;
    }
    for (int i = 1; i < 3; ++i) {
        cin >> dims[i];
    }
    return 1;
}

inline bool bit(int mask, int i) {
    return (mask >> i) & 1;
}

int brut() {
    const int D = *max_element(dims, dims + 3);
    int ans = 0;
    for (int a = 1; a <= D; ++a) {
        for (int b = a; b <= D; ++b) {
            for (int c = b; c <= D; ++c) {
                bool ok = 0;
                vi perm{a, b, c};
                do {
                    bool cur = 1;
                    forn(i, 3) {
                        cur &= dims[i] % perm[i] == 0;
                    }
                    ok |= cur;
                } while (next_permutation(all(perm)));
                ans += ok;
            }
        }
    }
    return ans;
}

const int MAX = 1e5 + 10;
const int M = 1 << 3;

int divs[MAX];
bool ok[M][M][M];

void precalc() {
    memset (divs, 0, sizeof divs);
    for (int d = 1; d < MAX; ++d) {
        for (int x = d; x < MAX; x += d) {
            ++divs[x];
        }
    }

    memset (ok, 0, sizeof ok);
    for (int m0 = 1; m0 < M; ++m0) {
        for (int m1 = m0; m1 < M; ++m1) {
            for (int m2 = m1; m2 < M; ++m2) {
                vi perm{m0, m1, m2};
                sort(all(perm));
                do {
                    bool cur = 1;
                    forn(i, 3) {
                        cur &= bit(perm[i], i);
                    }
                    if (cur) {
                        ok[m0][m1][m2] = 1;
                        break;
                    }
                } while (next_permutation(all(perm)));
            }
        }
    }
}

int C3(int n) {
    int ans = 0;
    ans += n * (n - 1) * (n - 2) / 6;
    ans += n * (n - 1);
    ans += n;
    return ans;
}

int C2(int n) {
    return n * (n - 1) / 2 + n;
}

int solve() {
    static int cnt[1 << 3];
    memset (cnt, 0, sizeof cnt);
    forn(mask, 1 << 3) {
        int g = 0;
        forn(i, 3) {
            if (bit(mask, i)) {
                g = gcd(g, dims[i]);
            }
        }
        if (!g) {
            assert(mask == 0);
            continue;
        }
        cnt[mask] += divs[g];
    }

    ford(mask, M) {
        for (int m = mask + 1; m < M; ++m) {
            if ((m & mask) == mask) {
                cnt[mask] -= cnt[m];
            }
        }
    }

    int ans = 0;
    for (int m0 = 1; m0 < M; ++m0) {
        for (int m1 = m0; m1 < M; ++m1) {
            for (int m2 = m1; m2 < M; ++m2) {
                if (!ok[m0][m1][m2]) {
                    continue;
                }
                cerr << bitset<3>(m0) << " " << bitset<3>(m1) << " " << bitset<3>(m2) << endl;
                cerr << cnt[m0] << " " << cnt[m1] << " " << cnt[m2] << endl;
                if (m0 == m1 && m1 == m2) {
                    ans += C3(cnt[m0]);
                } else if (m0 == m1) {
                    ans += C2(cnt[m0]) * cnt[m2];
                } else if (m1 == m2) {
                    ans += cnt[m0] * C2(cnt[m1]);
                } else {
                    ans += cnt[m0] * cnt[m1] * cnt[m2];
                }
            }
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    precalc();

    int T;
    cin >> T;

    forn(t, T) {
        assert(read());

        cout << solve() << "\n";

//        cout << brut() << "\n";

//        break;
    }

    return 0;
}