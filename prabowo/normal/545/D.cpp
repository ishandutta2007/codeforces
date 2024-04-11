#include<cstdio>
#include<algorithm>

int n;
long long t[100002];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &t[i]);

    std::sort(t, t+n);

    long long sum = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (sum <= t[i]) {
            ans++;
            sum += t[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}