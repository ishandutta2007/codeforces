#include <cstdio>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    vector <ll> a(n + 1), c1(n + 1), c2(n + 1), c3(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        a[i] += a[i - 1];
        c1[i] = 1;
    }
    map <ll, ll> f1, f2;
    for (int i = 1; i <= n; i++) {
        c2[i] = (a[i] % 2 == 0) ? f1[a[i] / 2] : 0;
        f1[a[i]] += c1[i];
    }
    for (int i = 1; i <= n; i++) {
        c3[i] = ((a[i] * 2) % 3 == 0) ? f2[(a[i] * 2) / 3] : 0;
        f2[a[i]] += c2[i];
    }
    printf("%I64d\n", c3[n]);
    return 0;
}