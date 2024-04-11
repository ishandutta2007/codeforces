#include <bits/stdc++.h>

using namespace std;

int a[3333];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int last = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > last) {
            last = a[i];
        } else {
            last++;
            ans += last - a[i];
        }
    }
    printf("%d\n", ans);
}