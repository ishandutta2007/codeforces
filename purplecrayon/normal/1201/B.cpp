#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 5;
int a[maxn];
 
int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
 
    if (accumulate(a, a + n, 0ll) & 1) {
        puts("NO");
        return 0;
    }
 
    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) sum += a[i];
    if (sum >= a[n - 1]) puts("YES");
    else puts("NO");
}