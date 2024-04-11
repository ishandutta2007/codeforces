#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n, m, k;
ll ans;

void modify_n(int x)
{
    if (1 <= x && x <= n); else return;
    int left = k - n / x + 1;
    if (0 <= left && left < m); else return;
    ans = max(ans, 1LL * x * (m / (left + 1)));
}

void modify_m(int x)
{
    if (1 <= x && x <= m); else return;
    int left = k - m / x + 1;
    if (0 <= left && left < n); else return;
    ans = max(ans, 1LL * x * (n / (left + 1)));
}

int main()
{
    ans = -1;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i * i <= n; i++)
    {
        modify_n(n / i);
        modify_n(n / i + 1);
        modify_n(n / i - 1);
        modify_n(i);
        modify_n(i + 1);
        modify_n(i - 1);
    }
    for (int i = 1; i * i <= m; i++)
    {
        modify_m(m / i);
        modify_m(m / i + 1);
        modify_m(m / i - 1);
        modify_m(i);
        modify_m(i + 1);
        modify_m(i - 1);
    }
    printf("%I64d\n", ans);
    return 0;
}