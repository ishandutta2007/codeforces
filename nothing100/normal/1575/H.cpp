#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
char a[510], b[510];
vector<int> fail;

vector<int> KMP(char *s, int n) {
    vector<int> f(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int j;
        for (j = f[i - 1]; j && s[j + 1] != s[i]; j = f[j]);
        if (s[j + 1] == s[i]) f[i] = j + 1;
    }
    return f;
}

int dp[2][510][510];
const int INF = 1e8;
int new_match[510][2];
int ans[510];

void upd(int &x, int y) {
    x = min(x, y);
}

int main() {
    scanf("%d%d",&n,&m);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    for (int i = 1; i <= n; i++) a[i] -= '0';
    for (int i = 1; i <= m; i++) b[i] -= '0';
    if (m == 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (a[i] == b[1]);
        for (int i = 0; i <= n - m + 1; i++) {
            ans[i] = abs(i - cnt);
        }
        for (int i = 0; i <= n - m + 1; i++) {
            if (ans[i] == INF) ans[i] = -1;
            printf("%d%c",ans[i]," \n"[i==n-m+1]);
        }
        return 0;
    }
    fail = KMP(b, m);
    /*
    for (int i = 1; i <= m; i++) {
        printf("fail %d = %d\n",i,fail[i]);
    }
    */
    new_match[0][b[1]] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= 1; j++) {
            if (b[i + 1] == j) {
                new_match[i][j] = i + 1;
            } else {
                new_match[i][j] = new_match[fail[i]][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n - m + 1; j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        int now = i & 1;
        int nxt = now ^ 1;
        /*
        for (int j = 0; j <= n - m + 1; j++) {
            for (int k = 0; k <= m; k++) {
                printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[now][j][k]);
            }
        }
        */
        if (i == n) break;
        for (int j = 0; j <= n - m + 1; j++) {
            for (int k = 0; k <= m; k++) {
                dp[nxt][j][k] = INF;
            }
        }
        for (int j = 0; j <= n - m + 1; j++) {
            int nv = a[i + 1];
            for (int k = 0; k < m - 1; k++) {
                int nk1 = new_match[k][nv];
                int nk2 = new_match[k][nv ^ 1];
                upd(dp[nxt][j][nk1], dp[now][j][k]);
                upd(dp[nxt][j][nk2], dp[now][j][k] + 1);
            }
            if (nv == b[m]) {
                int nk1 = new_match[fail[m - 1]][nv];
                int nk2 = new_match[m - 1][nv ^ 1];
                upd(dp[nxt][j + 1][nk1], dp[now][j][m - 1]);
                upd(dp[nxt][j][nk2], dp[now][j][m - 1] + 1);
            } else {
                int nk1 = new_match[m - 1][nv];
                int nk2 = new_match[fail[m - 1]][nv ^ 1];
                upd(dp[nxt][j][nk1], dp[now][j][m - 1]);
                upd(dp[nxt][j + 1][nk2], dp[now][j][m - 1] + 1);
            }
        }
    }
    for (int j = 0; j <= n - m + 1; j++) {
        ans[j] = INF;
        for (int k = 0; k <= m - 1; k++) {
            upd(ans[j], dp[n & 1][j][k]);
        }
    }
    //printf("?? %d\n",new_match[2][0]);
    for (int i = 0; i <= n - m + 1; i++) {
        if (ans[i] == INF) ans[i] = -1;
        printf("%d%c",ans[i]," \n"[i==n-m+1]);
    }
}