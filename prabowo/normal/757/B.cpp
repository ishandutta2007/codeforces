#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
bool sieve[N];
int cnt[N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    int ans = 1;
    for (int i=2; i<N; i++) {
        if (sieve[i]) continue;
        int tmp = 0;
        for (int j=i; j<N; j+=i)
            tmp += cnt[j],
            sieve[j] = true;

        ans = max(ans, tmp);
    }

    printf("%d\n", ans);
    return 0;
}