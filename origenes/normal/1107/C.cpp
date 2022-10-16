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

const int maxn = 212345;

int a[maxn], n, k;
char s[maxn];

int main() {
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) scanf("%d", a + i);
    scanf("%s", s + 1);
    char now = 0;
    ll ans = 0;
    priority_queue<int> q;
    s[n + 1] = 0;
    FOR(i, 1, n + 1) {
        if (s[i] != now) {
            int cnt = 0;
            while (!q.empty() && cnt++ < k) {
                ans += q.top();
                q.pop();
            }
            priority_queue<int> tmp;
            swap(tmp, q);
            now = s[i];
            q.push(a[i]);
        } else q.push(a[i]);
    }
    printf("%lld", ans);
}