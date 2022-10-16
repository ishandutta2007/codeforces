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

const int maxn = 512;

char mat[maxn][maxn];
int n, ans;

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%s", mat[i] + 1);
    FOR(i, 2, n - 1) FOR(j, 2, n - 1) if (mat[i][j] == 'X' && mat[i - 1][j - 1] == 'X' && mat[i - 1][j + 1] == 'X' && mat[i + 1][j - 1] == 'X' && mat[i + 1][j + 1] == 'X')
                ans++;
    printf("%d", ans);
}