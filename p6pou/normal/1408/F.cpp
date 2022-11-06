#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void conq(int l, int n) {
    if (n == 1) return;
    n >>= 1, conq(l, n), conq(l + n, n);
    for (int i = 0; i < n; i ++) printf("%d %d\n", l + i, l + n + i);
}
int main() {
    int N, n;
    scanf("%d", &N);
    for (n = 1; n << 1 < N; n <<= 1);
    printf("%d\n", n * (int)log2(n));
    conq(1, n), conq(N - n + 1, n);
    return 0;
}