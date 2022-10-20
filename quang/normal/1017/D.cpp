#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int M = 500010;

int n, m, q;
int w[N];
char a[N + 1];
int cnt[1 << N];

int getVal() {
    scanf("%s", a);
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res = (res << 1) + a[i] - '0';
    }
    return res;
}

int id[1 << N];
int pos[1 << N];
int numInSet[1 << N];

bool cmp(int u, int v) {
    return cnt[u] < cnt[v];
}

int dp[1 << N][1 << N];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", w + i);
    }
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) {
                sum += w[j];
            }
        }
        cnt[i] = sum;
        id[i] = i;
    }
    sort(id, id + (1 << n), cmp);
    for (int i = 0; i < (1 << n); i++) {
        pos[id[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        int foo = getVal();
        numInSet[foo]++;
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            int mask = i ^ j;
            dp[i][pos[j]] += numInSet[mask];
        }
        for (int j = 1; j < (1 << n); j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }
    while (q--) {
        int foo = getVal();
        int k;
        scanf("%d", &k);
        int low = -1, high = (1 << n);
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (cnt[id[mid]] > k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        printf("%d\n", dp[foo][low]);
    }
    return 0;
}