#include <bits/stdc++.h>
using namespace std;

char c[105][105];
int n,m;
int sum[105][105];
int i,j;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
    }
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m-1; j >=0; j--) {
            int cur_sum = sum[i+1][j] + sum[i][j+1] - sum[i+1][j+1];
            if (c[i][j] == 'B') {
                if (cur_sum != -1) {
                    ++res;
                }
                sum[i][j] = -1;
            } else if (c[i][j] == 'W') {
                if (cur_sum != 1) {
                    ++res;
                }
                sum[i][j] = 1;
            }
        }
    }
    printf("%d\n", res);
}