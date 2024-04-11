#include <cstdio>

int ni() {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    int sg = 0;
    if (c == '-') {
        c = getchar();
        sg = 1;
    }
    int ret = 0;
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return sg ? -ret : ret;

}

const int N = 333 * 333 * 333;
bool dp[3][N], dp2[N], win[N];
int a[5], sh[5], b[5];

int main() {
    int n = ni();
    for (int i = 0; i < n; i++) a[i] = ni();
    int ss = 1;
    for (int i = 0; i < n; i++) {
        sh[i] = ss;
        ss *= a[i] + 1;
    }
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp2[0] = 1;
    win[0] = 0;
    int sm = 0;
    for (int i = 0; i < n; i++) sm += sh[i];
    for (int i = 1; i < ss; i++) {
        for (int j = 0, cur = i; j < n; j++) {
            b[j] = cur % (a[j] + 1);
            cur /= a[j] + 1;
        }
        bool curw = 0;
        int cn = 0;
        for (int j = 0; j < n; j++) {
            if (b[j] == 0) continue;
            ++cn;
            int ni = i - sh[j];
            if (dp[j][ni]) {
                dp[j][i] = 1;
                curw = 1;
            }
        }        
        if (cn == n) {
            int ni = i - sm;
            if (dp2[ni]) {
                curw = 1;
                dp2[i] = 1;
            }
        }
        win[i] = curw;
        if (!curw) {
            for (int j = 0; j < n; j++) dp[j][i] = 1;
            dp2[i] = 1;
        }
    }
    int last = 0;
    for (int i = 0;i < n; i++) last += a[i] * sh[i];
    puts(win[last] ? "BitLGM" : "BitAryo");
}