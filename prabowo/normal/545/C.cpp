#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define INF 2000000002

typedef pair<int, int> pii;

int n;
pii pohon[100002];
int dp[100002][2];

int f(int x, int state) {
    if (x == 0) return 0;
    if (dp[x][state] != -1) return dp[x][state];

    int &ret = dp[x][state];
    ret = f(x-1, 0);
    if (pohon[x].fi - pohon[x].se > pohon[x-1].fi) ret = max(ret, 1 + f(x-1, 1));
    if (state == 1 && pohon[x].fi + pohon[x].se < pohon[x+1].fi - pohon[x+1].se) ret = max(ret, 1 + f(x-1, 0));
    if (state == 0 && pohon[x].fi + pohon[x].se < pohon[x+1].fi) ret = max(ret, 1 + f(x-1, 0));

    return ret;
}

int main() {
    scanf("%d", &n);

    pohon[0] = mp(-INF, 0);
    for (int i=1; i<=n; i++) scanf("%d %d", &pohon[i].fi, &pohon[i].se);
    pohon[n+1] = mp(INF, 0);

    memset(dp, -1, sizeof dp);
    printf("%d\n", f(n, 0));

    return 0;
}