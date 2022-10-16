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
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

int n, m;
char s[maxn], t[maxn];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
    if (m < n - 1) {
        puts("NO");
        return 0;
    }
    if (s[0] == '*') {
        FOR(i, 1, n - 1) {
            if (s[n - i] != t[m - i]) {
                puts("NO");
                return 0;
            }
        }
    } else if (s[n - 1] == '*') {
        REP(i, n - 1) {
            if (s[i] != t[i]) {
                puts("NO");
                return 0;
            }
        }
    } else {
        int p = -1;
        REP(i, n) {
            if (s[i] == '*') {
                p = i + 1;
                break;
            }
            if (s[i] != t[i]) {
                puts("NO");
                return 0;
            }
        }
        FOR(i, 1, n - p) {
            if (s[n - i] != t[m - i]) {
                puts("NO");
                return 0;
            }
        }
        if (p == -1 && n != m) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}