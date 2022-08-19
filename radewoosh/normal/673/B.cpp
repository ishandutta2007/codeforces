#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int low = 1, high = n;
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        low = max(low, a);
        high = min(high, b);
    }
    printf("%d\n", max(0, high - low));
    return 0;
}