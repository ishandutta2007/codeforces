#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    scanf("%I64d", &n);
    if (n % 2 == 1) printf("%I64d\n", -(n + 1) / 2); else printf("%I64d\n", +(n + 1) / 2);
    return 0;
}