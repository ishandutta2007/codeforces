#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 512345;

int d[maxn], n, cnt[maxn];
ll s;

int check(int now) {
    reset(cnt, 0);
    REP(i, n) cnt[d[i]]++;
    cnt[now]++;
    int buff = 0, pos = 0;
    ll L = 0, R = 0;
    REP(i, n + 1) {
        int cur = (pos == i && (pos == n || d[pos] < now)) ? now : d[pos++];
        L += cur;
        cnt[cur]--;
        R -= min(cur, i);
        buff += cnt[i];
        R += n - i - buff;
        if (L > R + ll(i + 1) * i) return i == pos ? 1 : -1;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", d + i);
        s += d[i];
    }
    sort(d, d + n, greater<int>());
    bool flag = s & 1;
    int L = 0, R = n - flag >> 1;
    pii ans = mp(-1, -1);
    while (L <= R) {
        int M = L + R >> 1;
        if (check(2 * M + flag) == -1) {
            L = M + 1;
        } else {
            ans._1 = M;
            R = M - 1;
        }
    }
    L = ans._1, R = n - flag >> 1;
    while (L <= R) {
        int M = L + R >> 1;
        if (check(2 * M + flag) == 1) {
            R = M - 1;
        } else {
            ans._2 = M;
            L = M + 1;
        }
    }
    if (ans._1 == -1 || ans._2 == -1) puts("-1");
    else FOR(i, ans._1, ans._2) printf("%d ", 2 * i + flag);

}