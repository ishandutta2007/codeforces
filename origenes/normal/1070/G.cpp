#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123;

int n, m, a[maxn], L = maxn, R = -1, mvL[maxn], mvR[maxn];
vector<int> ans;
pii heros[maxn];

bool mL(int rr) {
    int ok = rr + 1;
    bool vis[maxn] = {};
    ROF(i, rr, L) {
        if (heros[i] == mp(0, 0)) continue;
        if (mvR[i] >= ok - 1) {
            ok = i;
            vis[i] = true;
            ans.pb(heros[i]._1);
        }
    }
    if (ok > L) return false;
    FOR(i, L, rr) if (heros[i] != mp(0, 0) && !vis[i]) ans.pb(heros[i]._1);
    return true;
}

bool mR(int rr) {
    int ok = rr - 1;
    bool vis[maxn] = {};
    FOR(i, rr, R) {
        if (heros[i] == mp(0, 0)) continue;
        if (mvL[i] <= ok + 1) {
            ok = i;
            vis[i] = true;
            ans.pb(heros[i]._1);
        }
    }
    if (ok < R) return false;
    FOR(i, rr, R) if (heros[i] != mp(0, 0) && !vis[i]) ans.pb(heros[i]._1);
}

int main() {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        int s, h;
        scanf("%d%d", &s, &h);
        heros[s] = mp(i, h);
        L = min(s, L);
        R = max(s, R);
    }
    FOR(i, 1, n) scanf("%d", a + i);
    FOR(i, 1, n) if (heros[i] != mp(0, 0)) {
            int acc = heros[i]._2;
            ROF(j, i - 1, 1) {
                if (acc + a[j] < 0) {
                    mvL[i] = j + 1;
                    break;
                } else acc += a[j];
            }
            if (!mvL[i]) mvL[i] = 1;
            acc = heros[i]._2;
            FOR(j, i + 1, n) {
                if (acc + a[j] < 0) {
                    mvR[i] = j - 1;
                    break;
                } else acc += a[j];
            }
            if (!mvR[i]) mvR[i] = n;
        }
    int flag = 0;
    FOR(rr, 1, n) {
        ans.clear();
        if (mR(rr) && ans.size() && mL(rr - 1)) {
            flag = rr;
            break;
        }
        if (mL(rr) && ans.size() && mR(rr + 1)) {
            flag = rr;
            break;
        }
    }
    if (flag) {
        printf("%d\n", flag);
        for (auto it : ans) printf("%d ", it);
    } else puts("-1");
    return 0;
}