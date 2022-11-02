#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, k, d1, d2;

bool check(int z1, int z2)
{
    ll help = k - 2 * z1 * d1 -  z2 * d2;
    if (help < 0 || help % 3 != 0) return false;
    ll c1 = help / 3;
    ll c2 = c1 + z1 * d1;
    ll c3 = c2 + z2 * d2;
    if (c1 < 0 || c2 < 0 || c3 < 0) return false;
    ll big = max(max(c1, c2), c3);
    help = n - k + c1 + c2 + c3 - big - big - big;
    return ((help >= 0 && help % 3 == 0) ? true : false);
}

int main()
{
    int tests;
    scanf("%d", &tests);
    for (int i = 1; i <= tests; i++)
    {
        scanf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
        bool ok = check(-1, -1) | check(-1, +1) | check(+1, -1) | check(+1, +1);
        puts((ok) ? "yes" : "no");
    }
    return 0;
}