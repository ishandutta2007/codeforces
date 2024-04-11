#include <bits/stdc++.h>
using namespace std;

int N, a[2005], cnt[5005];
long long gre[5005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a, a + N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x = a[j] - a[i];
            cnt[x]++;
        }
    }
    long long sum = 0;
    for (int i = 5003; i >= 0; i--) {
        gre[i] = sum;
        sum += cnt[i];
    }
    long double ans = 0;
    for (int i = 0; i <= 5003; i++) {
        for (int j = 0; j <= 5003; j++) {
            if (i + j >= 5003) continue;
            ans += (long double)cnt[i] * cnt[j] * gre[i + j];
        }
    }
    for (int i = 0; i < 3; i++) ans /= N * (N - 1)/2;
    cout << ans << endl;
}