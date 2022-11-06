#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int k = min(a, d);
    int ans1 = k * e + min(min(b, c), d - k) * f;
    k = min(min(b, c), d);
    int ans2 = k * f + min(a, d - k) * e;
    printf("%d\n", max(ans1, ans2));
    return 0;
}