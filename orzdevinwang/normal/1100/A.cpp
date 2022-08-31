#include<bits/stdc++.h>
#define N 110
#define R(i, j, k) for(int i = j; i <= k; i++)
#define L(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
int n, k, a[N], sum, ssum, ans;
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
    for(int i = 1; i <= k; i++) {
        ssum = sum;
        for(int j = i; j <= n; j += k) ssum -= a[j];
        ans = max(ans, abs(ssum));
    }
    printf("%d\n", ans);
    return 0;
}