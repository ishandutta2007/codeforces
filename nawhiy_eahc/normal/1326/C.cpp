#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 998244353;

int k, n, a[200006];
long long ans;
vector<int> v;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (a[i] >= n - k + 1) v.push_back(i), ans += a[i];
    }
    long long res = 1;
    for (int i = 1; i < k; i++) res *= v[i] - v[i - 1], res %= MOD;
    printf("%lld %lld", ans, res);
}