#include <cstdio>
#include <map>

using namespace std;
const int N = 1e6 + 10;

int f[N], a[N], c1[N], c2[N];

void add(int i) {
    for (int x = i; x < N; x = (x | (x + 1))) f[x]++;
}

int getsum(int i) {
    int res = 0;
    for (int x = i; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    map <int, int> m1, m2;
    for (int i = 1; i <= n; i++) {
        m1[a[i]]++;
        c1[i] = m1[a[i]];
    }
    for (int i = n; i >= 1; i--) {
        m2[a[i]]++;
        c2[i] = m2[a[i]];
    }
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += getsum(c1[i] - 1);
        add(c2[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}