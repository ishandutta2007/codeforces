#include <bits/stdc++.h>
using namespace std;

int N, K, arr[200005];

int main() {
    scanf("%d%d",&N, &K);
    for (int i = 0; i <= N; i++) scanf("%d", &arr[i]);
    long long cur = 0, stop = N;
    for (int i = 0; i <= N; i++) {
        cur += arr[i];
        if (cur % 2 != 0 || i == N) {
            stop = i;
            break;
        } else cur /= 2;
    }
    long long cur2 = 0;
    for (int i = N; i > stop; i--) {
        cur2 -= arr[i];
        if (abs(cur2) > 1000000ll * 2500000000ll) {
            printf("0\n");
            return 0;
        }
        cur2 *= 2;
    }
    long long diff = cur2 - cur;
    int ans = 0;
    //printf("stop: %d %lld\n", stop, diff);
    for (int i = stop; i >= 0; i--) {
        if (abs((long long)arr[i] + diff) <= K) {
            ans++;
            //printf("change %d to %lld\n", i, (long long)arr[i] + diff);
        }
        if (i == N && (long long)arr[i] + diff == 0) ans--;
        diff *= 2;
        if (abs(diff) > 10ll * K) break;
    }
    printf("%d\n", ans);
}