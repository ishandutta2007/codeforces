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

char s[maxn];
int ans[maxn], cnt;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    ROF(i, n - 1, 0) {
        if (s[i] == 'a' && cnt % 2 == 0) ans[i] = 1, cnt++;
        if (s[i] == 'b' && cnt % 2 == 1) ans[i] = 1, cnt++;
    }
    REP(i, n) printf("%d ", ans[i]);
}