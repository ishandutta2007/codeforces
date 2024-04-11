#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
char a[N], b[N];
int cnt[2][2];

int main() {
    scanf("%d", &n);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    memset(cnt, 0, sizeof cnt);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '0') {
            if (b[i] == '0') {
                res += cnt[1][0];
                res += cnt[1][1];
                cnt[0][0]++;
            } else {
                res += cnt[1][0];
                cnt[0][1]++;
            }
        } else {
            if (b[i] == '0') {
                res += cnt[0][0];
                res += cnt[0][1];
                cnt[1][0]++;
            } else {
                res += cnt[0][0];
                cnt[1][1]++;
            }
        }
    }
    cout << res << endl;
    return 0;
}