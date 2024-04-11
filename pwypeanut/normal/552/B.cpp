#include <bits/stdc++.h>
using namespace std;

int N;
const int digit[] = {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};

int main() {
    scanf("%d", &N);
    long long ans = 0;
    int cur = 0;
    while (N > 0) {
        if (digit[cur] < N) {
            N -= digit[cur];
            ans += (long long)(cur + 1) * digit[cur];
            cur++;
        }
        else {
            ans += (long long)(cur + 1) * N;
            N = 0;
            break;
        }
        if (cur == 9) break;
    }
    if (N > 0) ans += (long long)N * 10;
    cout << ans << endl;
}