#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = 0;
    ans = max(ans, a + b + c);
    ans = max(ans, a * b + c);
    ans = max(ans, a * b * c);
    ans = max(ans, a + b * c);
    ans = max(ans, (a + b) * c);
    ans = max(ans, a * (b + c));
    printf("%d\n", ans);
    return 0;
}