#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, m, k;

bool check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++) cnt += min(m, x / i);
    return (cnt >= k);
}

int main()
{
    scanf("%I64d %I64d %I64d", &n, &m, &k);
    ll left = 0, right = n * m;
    while (right - left > 1)
    {
        ll middle = (left + right) / 2;
        if (check(middle)) right = middle; else left = middle;
    }
    printf("%I64d\n", right);
    return 0;
}