#include <iostream>
#include <cmath>


int nextInt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int MAX = 123456;

int x[MAX];
int y[MAX];
int time_[MAX];
int dp[MAX];

using namespace std;


int main() {
    int r = nextInt();
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            time_[i + 1] = nextInt();
            x[i + 1] = nextInt() - 1;
            y[i + 1] = nextInt() - 1;
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = -1e9;
        }
        int res = 0;
        for (int cur = 0; cur <= n; cur++) {
            int now = dp[cur];
            if (now < 0) {
                continue;
            }
            res = max(res, now);
            int to = min(n, cur + 4 * r + 3);
            for (int next = cur + 1; next <= to; next++) {
                int dx = x[next] - x[cur], dy = y[next] - y[cur];
                int dist = abs(dx) + abs(dy);
                if (time_[cur] + dist <= time_[next]) {
                    dp[next] = max(dp[next], now + 1);
                }
            }
        }
        printf("%d\n", res);
}