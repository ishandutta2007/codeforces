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

const int maxn = 123456;

int a[maxn], nxt[maxn], n;
vector<int> pos;
set<int> s;
ll ans;

bool lucky(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    pos.pb(-1);
    REP(i, n) if (lucky(a[i])) pos.pb(i);
    FOR(i, 1, int(pos.size()) - 1) {
        nxt[i] = pos.size();
        FOR(j, i + 1, int(pos.size()) - 1) if (a[pos[j]] == a[pos[i]]) {
                nxt[i] = j;
                break;
            }
    }
    ans = (unsigned long long)(n + 2) * (n + 1) / 2 * n / 3 * (n - 1) / 4;
    FOR(i, 1, int(pos.size()) - 1) {
        s.clear();
        s.insert(pos[i]);
        s.insert(n);
        ll now = 0, seg = pos[i + 1] - pos[i];
        ROF(j, i, 1) {
            if (nxt[j] > i) for (int k = nxt[j]; k < pos.size(); k = nxt[k]) {
                    decltype(s.begin()) pre, nex;
                    pre = nex = s.insert(pos[k])._1;
                    pre--, nex++;
                    if (pre == s.begin()) now += (seg * (seg + 1) / 2 + seg * (pos[k] - pos[i + 1]))* (*nex - pos[k]);
                    else now += seg * (*nex - pos[k]) * (pos[k] - *pre);
                }
            ans -= now * (pos[j] - pos[j - 1]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}