#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 50001

using namespace std;

int n;
long long k;
long long a[N];

int main() {
   // fi, fo;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", a + i);
        k += a[i];
    }
    k /= n;
    long long res = 0;
    for(int i = 1; i < n; i++) {
        res += abs(a[i] - k);
        a[i + 1] += a[i] - k;
    }
    printf("%I64d", res);
    return 0;
}