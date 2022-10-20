#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int C = 5100000;
const int MAX_ANS = 16;

int n, q;
int primeDivisor[C];
int a[N];

void init() {
    for (int i = 2; i < C; i++) {
        if (!primeDivisor[i]) {
            for (int j = i; j < C; j += i) {
                if (!primeDivisor[j]) {
                    primeDivisor[j] = i;
                }
            }
        }
    }
}

int normalize(int u) {
    int res = 1;
    while (u > 1) {
        int x = primeDivisor[u];
        int f = 0;
        while (u % x == 0) {
            u /= x;
            f ^= 1;
        }
        if (f) {
            res *= x;
        }
    }
    return res;
}

vector<int> last[C];
int dp[MAX_ANS][N];

vector<int> getDivs(int u) {
    vector<int> res;
    while (u > 1) {
        int x = primeDivisor[u];
        res.push_back(x);
        u /= x;
    }
    return res;
}

int main() {
    init();
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i] = normalize(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        // cout << "go " << i << endl;
        for (int j = 0; j < MAX_ANS; j++) {
            dp[j][i] = dp[j][i - 1];
        }
        vector<int> divs = getDivs(a[i]);
        for (int mask = 0; mask < (1 << (int)divs.size()); mask++) {
            int val = 1;
            int cnt = 0;
            for (int j = 0; j < divs.size(); j++) {
                if (mask & (1 << j)) {
                    val *= divs[j];
                } else {
                    cnt++;
                }
            }
            for (int j = 0; j < last[val].size(); j++) {
                if (j + cnt < MAX_ANS) {
                    // cout << cnt << " " << val << " " << j << " " << last[val][j] << endl;
                    dp[j + cnt][i] = max(dp[j + cnt][i], last[val][j]);
                }
            }
        }

        for (int mask = 0; mask < (1 << (int)divs.size()); mask++) {
            int val = 1;
            int cnt = 0;
            for (int j = 0; j < divs.size(); j++) {
                if (mask & (1 << j)) {
                    val *= divs[j];
                } else {
                    cnt++;
                }
            }
            if (last[val].size() <= cnt) {
                last[val].resize(cnt + 1, 0);
            }
            last[val][cnt] = i;
        }

        // cout << "debug " << i << " " << endl;
        // for (int j = 0; j <= 5; j++) {
        //     cout << dp[j][i] << " ";
        // }
        // cout << endl;
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int res = 0;
        while (dp[res][r] < l) {
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}