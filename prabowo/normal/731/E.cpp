#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int pre[N];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", pre + i);
    for (int i=1; i<n; i++) pre[i] += pre[i-1];
    
    int ans = pre[n-1];
    for (int i=n-2; i; i--) ans = max(ans, pre[i] - ans);

    printf("%d\n", ans);
    return 0;
}