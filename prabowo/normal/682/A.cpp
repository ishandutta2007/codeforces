#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf ("%d %d", &n, &m);
    
    long long ans = 0;
    for (int i=0; i<n;) {
        ans += (m + ++i % 5) / 5;
    }
    
    printf ("%lld\n", ans);
    return 0;
}