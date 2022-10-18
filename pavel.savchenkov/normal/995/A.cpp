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

int n, k;
vector<vi> a;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> k;

    a.clear();
    a.resize(4);
    forn(i, 4) {
        a[i].resize(n);
        forn(j, n) {
            cin >> a[i][j];
        }
    }
    return 1;
}

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
const int INF = 1e9;

bool in(int r, int c) {
    return 1 <= r && r <= 2 && 0 <= c && c < n;
}

int man_dist(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

vector<vi> moves;

bool move(const int w) {
    auto make_empty = [&](int r, int c) -> bool {
        if  (a[r][c] == w) {
            assert(r == 0 || r == 3);
            return 1;
        }

        vvi dist(4, vi(n, INF));
        vector<vector<pii>> prev(4, vector<pii>(n, mp(-1, -1)));
        dist[r][c] = 0;
        queue<pii> q;
        q.push(mp(r, c));
        int destr = -1;
        int destc = -1;
        while (!q.empty()) {
            int rr, cc;
            tie(rr, cc) = q.front();
            q.pop();

            assert(a[rr][cc] != w);

            if  (a[rr][cc] == 0) {
                destr = rr;
                destc = cc;
                break;
            }

            forn(d, 4) {
                int nr = rr + dr[d];
                int nc = cc + dc[d];
                if  (!in(nr, nc) || dist[nr][nc] <= dist[rr][cc] + 1 || a[nr][nc] == w) {
                    continue;
                }
                dist[nr][nc] = dist[rr][cc] + 1;
                prev[nr][nc] = mp(rr, cc);
                q.push(mp(nr, nc));
            }
        }

        if  (destr == -1) {
            return 0;
        }

        while (!(destr == r && destc == c)) {
            int rr, cc;
            tie(rr, cc) = prev[destr][destc];
            moves.pb({a[rr][cc], destr + 1, destc + 1});
            swap(a[destr][destc], a[rr][cc]);
            destr = rr;
            destc = cc;
        }

        assert(a[r][c] == 0);
        return 1;
    };

    int r = -1;
    int c = -1;
    for (int rr = 1; rr <= 2; ++rr) {
        forn(cc, n) {
            if  (a[rr][cc] == w) {
                r = rr;
                c = cc;
                break;
            }
        }
    } 

    if  (r == -1) {
        return 1;
    } 

    int r2 = -1;
    int c2 = -1;
    forn(rr, 4) {
        if  (1 <= rr && rr <= 2) {
            continue;
        }
        forn(cc, n) {
            if  (a[rr][cc] == w) {
                r2 = rr;
                c2 = cc;
                break;
            }
        }
    }

    assert(r2 != -1);

    while (!(r == r2 && c == c2)) {
        int tor = -1;
        int toc = -1;
        int best_dist = INF;
        forn(d, 4) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if  (nr == r2 && nc == c2) {
                best_dist = -1;
                tor = r2;
                toc = c2;
                break;
            }
            if  (!in(nr, nc)) {
                continue;
            }
            int cur_dist = man_dist(nr, nc, r2, c2);
            if  (cur_dist < best_dist) {
                tor = nr;
                toc = nc;
                best_dist = cur_dist;
            }
        }

        eprintf("r=%d, c=%d, w=%d, tor=%d, toc=%d, r2=%d, c2=%d\n", r, c, w, tor, toc, r2, c2);

        if  (!make_empty(tor, toc)) {
            return 0;
        }

        moves.pb({w, tor + 1, toc + 1});
        swap(a[r][c], a[tor][toc]);
        if  (tor == r2 && toc == c2) {
            a[r][c] = 0;
        }
        r = tor;
        c = toc;
    }

    return 1;
}

bool solve() {
    moves.clear();
    for (int w = 1; w <= k; ++w) {
        move(w);
    }
    for (int w = 1; w <= k; ++w) {
        if  (!move(w)) {
            return 0;
        }
    }
    assert(sz(moves) <= 20000);
    cout << sz(moves) << endl;
    for (const auto& it : moves) {
        cout << it[0] << " " << it[1] << " " << it[2] << "\n";
    }
    cout << endl;

    forn(i, sz(a)) {
        forn(j, sz(a[i])) {
            eprintf("%d ", a[i][j]);
        }
        eprintf("\n");
    }
    return 1;
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

    while (read()) {
        if  (!solve()) {
            cout << -1 << endl;
        }
    }

    return 0;
}