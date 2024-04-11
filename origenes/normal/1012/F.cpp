#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 22;
const int inf = 0x3f3f3f3f;

struct Trip {
    int id, ids, s, len, t;

    bool operator<(const Trip &rhs) const {
        return t < rhs.t;
    }
};

Trip trips[maxn];
int dp[1 << maxn], idt[maxn], n, p, ALL;
pii ans[1 << maxn], res[maxn];
vector<pii> intervals[2];           // {starting time, ending time (valid)}
unordered_map<int, int> mmap;

inline bool cmp(const Trip &lhs, const Trip &rhs) {
    return lhs.s < rhs.s;
}

void init() {
    ALL = (1 << n) - 1;
    REP(i, n) mmap[1 << i] = i;
    memset(dp, 0x3f, sizeof(dp));
    sort(trips, trips + n, cmp);
    REP(i, n) trips[i].ids = i;
    intervals[0] = {mp(1, inf)};
    int u = 0, v = 1;
    REP(i, n) {
        intervals[v] = intervals[u];
        intervals[v].pop_back();
        if (intervals[u].back()._1 < trips[i].s) intervals[v].pb(mp(intervals[u].back()._1, trips[i].s - 1));
        intervals[v].pb(mp(trips[i].s + trips[i].len, inf));
        swap(u, v);
    }
    intervals[1] = intervals[u];
    dp[0] = 0;
    sort(trips, trips + n);
    REP(i, n) idt[trips[i].ids] = i;
}

inline int getT(int t1, int t2) {
    return t2 == inf ? inf : t2 - t1;
}

void update(int s, int now, int &p1, int &p2) {     // p1 = position in ALL, p2 = position in s
    int st = max(intervals[0][p2]._1, dp[s]), ss = s | (1 << trips[now].ids);
    while (st > intervals[1][p1]._2) p1++;
    if (st < intervals[1][p1]._1) st = intervals[1][p1]._1;
    while (getT(st, intervals[0][p2]._2) < trips[now].t) {
        p2++;
        while (intervals[1][p1]._1 < intervals[0][p2]._1) {
            p1++;
            st = intervals[1][p1]._1;
        }
    }
    if (dp[ss] > st + trips[now].t) {         // cannot get the visa before trip starts
        int tmp = dp[ss];
        dp[ss] = st + trips[now].t;
        if (dp[ss] >= trips[now].s) {
            dp[ss] = tmp;
            return;
        }
        ans[ss] = mp(s, st);
    }
}

void print(int ps, int s) {
    if (!s) return;
    res[trips[mmap[s ^ ans[s]._1]].id] = mp(ps, ans[s]._2);
    print(ps, ans[s]._1);
}

int main() {
    scanf("%d%d", &n, &p);
    REP(i, n) {
        scanf("%d%d%d", &trips[i].s, &trips[i].len, &trips[i].t);
        trips[i].id = i;
    }
    init();
    REP(s, 1 << n) {
        if (dp[s] == inf) continue;
        int p1 = 0, p2 = 0;
        intervals[0] = {mp(1, inf)};
        REP(i, n) {
            if (s & (1 << i)) {
                pii tmp = intervals[0].back();
                if (tmp._1 < trips[idt[i]].s) intervals[0].back()._2 = trips[idt[i]].s - 1;
                else intervals[0].pop_back();
                intervals[0].pb(mp(trips[idt[i]].s + trips[idt[i]].len, inf));
            }
        }
        REP(i, n) {                     // iterate according to rank
            if (s & (1 << trips[i].ids)) continue;
            update(s, i, p1, p2);
        }
    }
    sort(trips, trips + n, cmp);
    if (p == 1) {
        if (dp[ALL] < inf) {
            puts("YES");
            print(1, ALL);
            REP(i, n) printf("%d %d\n", res[i]._1, res[i]._2);
        } else puts("NO");
    } else {
        bool flag = false;
        REP(s, 1 << n) {
            if (dp[s] < inf && dp[ALL ^ s] < inf) {
                puts("YES");
                print(1, s);
                print(2, ALL ^ s);
                REP(i, n) printf("%d %d\n", res[i]._1, res[i]._2);
                flag = true;
                break;
            }
        }
        if (!flag) puts("NO");
    }
    return 0;
}