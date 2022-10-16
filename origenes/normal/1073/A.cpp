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

const int maxn = 1234;

int n;
char s[maxn];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    if (n == 1) {
        puts("NO");
        return 0;
    }
    FOR(i, 1, n - 1) {
        if (s[i] != s[i + 1]) {
            puts("YES");
            putchar(s[i]);
            putchar(s[i + 1]);
            return 0;
        }
    }
    puts("NO");
    return 0;
}