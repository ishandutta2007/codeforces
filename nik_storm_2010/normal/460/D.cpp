#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 20;

ll l, r, k, ans;
bool used[N], res[N];

void solve(int d, int sum, ll cur)
{
    if (sum > k) return;
    if (l + d > r)
    {
        if (ans < cur || sum == 0) return;
        ans = cur;
        for (int i = 0; i < N; i++) res[i] = used[i];
        return;
    }
    used[d] = 1;
    solve(d + 1, sum + 1, cur ^ (l + d));
    used[d] = 0;
    solve(d + 1, sum, cur);
}

int main()
{
    scanf("%I64d %I64d %I64d", &l, &r, &k);
    ans = 1e18;
    if (r - l <= 10)
    {
        solve(0, 0, 0);
        printf("%I64d\n", ans);
        int cnt = 0;
        for (int i = 0; i < N; i++) if (res[i]) cnt++;
        printf("%d\n", cnt);
        for (int i = 0; i < N; i++) if (res[i]) printf("%I64d ", l + i);
        return 0;
    }
    if (k == 1)
    {
        printf("%I64d\n1\n%I64d", l, l);
        return 0;
    }
    if (k == 2)
    {
        if (l % 2 == 1) l++;
        printf("1\n2\n%I64d %I64d", l, l + 1);
        return 0;
    }
    if (k == 3)
    {
        for (int i = 62; i >= 2; i--)
        {
            ll c1 = (1LL << i) - 1;
            ll c2 = (1LL << i) + (1LL << (i - 1)) - 1;
            ll c3 = (1LL << i) + (1LL << (i - 1));
            if (l <= c1 && c3 <= r)
            {
                printf("0\n3\n%I64d %I64d %I64d", c1, c2, c3);
                return 0;
            }
        }
        if (l % 2 == 1) l++;
        printf("1\n2\n%I64d %I64d", l, l + 1);
        return 0;
    }
    if (l % 2 == 1) l++;
    printf("0\n4\n%I64d %I64d %I64d %I64d", l, l + 1, l + 2, l + 3);
    return 0;
}