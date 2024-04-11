#include <bits/stdc++.h>
using namespace std;

int N, arr[300005], l[300005], r[300005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    l[0] = arr[0];
    for (int i = 1; i < N; i++) l[i] = min(l[i-1] + 1, arr[i]);
    r[N-1] = arr[N-1];
    for (int i = N-2; i >= 0; i--) r[i] = min(r[i+1] + 1, arr[i]);
    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, min(min(l[i], r[i]), min(i + 1, N - i)));
    printf("%d\n", ans);
}