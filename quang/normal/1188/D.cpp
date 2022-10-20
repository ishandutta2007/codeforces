#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 60;
const long long INF = (1ll << 60);

int n;
long long a[N];
int id[LOG][N];
int pos[LOG][N];
long long dp[LOG][N];

inline int getBit(long long u, int v) {
    return (u >> v) & 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;   
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    long long maxVal = *max_element(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = maxVal - a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        id[0][i] = i;
        pos[0][i] = i;
    }
    for (int i = 1; i < LOG; i++) {
        int numZero = 0;
        for (int j = 1; j <= n; j++) {
            numZero += getBit(a[id[i - 1][j]], i - 1) == 0;
        }
        int cnt[2] = {0, 0};
        for (int j = 1; j <= n; j++) {
            int idNow = id[i - 1][j];
            int foo = getBit(a[idNow], i - 1); 
            cnt[foo]++;
            int now = cnt[foo] + foo * numZero;
            id[i][now] = idNow;
            pos[i][idNow] = now;
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = INF;
    }
    dp[0][n + 1] = 0;
    for (int i = 0; i + 1 < LOG; i++) {
        for (int j = 1; j <= n + 1; j++) {
            dp[i + 1][j] = INF;
        }

        //add zero
        int need = 0;
        for (int j = 1; j <= n; j++) {
            int idNow = id[i][j];
            need += getBit(a[idNow], i);
        }

        int minVal = n + 1;
        for (int j = n + 1; j; j--) {
            if (j <= n) {
                int idNow = id[i][j];
                int foo = getBit(a[idNow], i);
                if (!foo) {
                    need++;
                } else {
                    need--;
                    minVal = min(minVal, pos[i + 1][idNow]);
                }
            }
            dp[i + 1][minVal] = min(dp[i + 1][minVal], dp[i][j] + need);
        }
       
        //add one
        need = 0;
        minVal = n + 1;
        for (int j = 1; j <= n; j++) {
            int idNow = id[i][j];
            int foo = getBit(a[idNow], i);
            need += (foo == 0);
            if (foo) minVal = min(minVal, pos[i + 1][idNow]);
        }   
        for (int j = n + 1; j; j--) {
            if (j <= n) {
                int idNow = id[i][j];
                int foo = 1 - getBit(a[idNow], i);
                if (!foo) {
                    need++;
                } else {
                    need--;
                    minVal = min(minVal, pos[i + 1][idNow]);
                }
            }
            dp[i + 1][minVal] = min(dp[i + 1][minVal], dp[i][j] + need);
        }
    }
    long long res = INF;
    for (int i = 1; i <= n + 1; i++) {
        res = min(res, dp[LOG - 1][i] + n + 1 - i);
    }
    cout << res << endl;
    return 0;
}