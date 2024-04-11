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

const int maxn = 123456;

char s[maxn * 2];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) s[i + n] = s[i];
    int ans = 1;
    REP(i, n) {
        if (s[i + 1] == s[i]) continue;
        else {
            int now = 1, j;
            for (j = i + 1; j < n + i; j++) {
                if (s[j] != s[j - 1]) now++;
                else break;
            }
            ans = max(ans, now);
            i = j - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}