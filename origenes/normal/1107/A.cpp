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

const int maxn = 312;

int n, q;
char s[maxn];

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d%s", &n, s + 1);
        if (n == 2) {
            if (s[1] >= s[2]) puts("NO");
            else {
                puts("YES\n2");
                printf("%c %s\n", s[1], s + 2);
            }
        } else {
            puts("YES\n2");
            printf("%c %s\n", s[1], s + 2);
        }
    }
}