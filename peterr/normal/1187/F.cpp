#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 2E5;
int indicator[MAXN + 1];
int lt[MAXN + 1];
int rt[MAXN + 1];
int len[MAXN + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        b = (int) ((long long) b * b % MOD);
        e >>= 1;
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    else if (a < 0)
        a += MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lt[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> rt[i];
        len[i] = rt[i] - lt[i] + 1;
    }
    lt[0] = rt[0] = 0;
    len[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int bot = max(lt[i], lt[i - 1]);
        int top = min(rt[i], rt[i - 1]);
        if (top >= bot)
        {
            int inter = top - bot + 1;
            indicator[i] = (int) ((long long) inter * modinv((int) ((long long) len[i] * len[i - 1] % MOD)) % MOD);
            indicator[i] = 1 - indicator[i];
            add(indicator[i], 0);
        }
        else
            indicator[i] = 1;
        add(ans, indicator[i]);
    }
    ans = (int) ((long long) ans * ans % MOD);
    for (int i = 1; i <= n; i++)
    {
        add(ans, -(int) ((long long) indicator[i] * indicator[i] % MOD));
        add(ans, indicator[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        int temp = (int) ((long long) 2 * indicator[i] * indicator[i - 1] % MOD);
        add(ans, -temp);
        int match1 = 1 - indicator[i - 1];
        add(match1, 0);
        int match2 = 1 - indicator[i];
        add(match2, 0);
        int bot = max(max(lt[i - 2], lt[i - 1]), lt[i]);
        int top = min(min(rt[i - 2], rt[i - 1]), rt[i]);
        int match3 = 0;
        if (top >= bot)
        {
            int total = (int) ((long long) len[i - 2] * len[i - 1] % MOD);
            total = (int) ((long long) total * len[i] % MOD);
            match3 = (int) ((long long) (top - bot + 1) * modinv(total) % MOD);
        }
        int someMatch = match1;
        add(someMatch, match2);
        add(someMatch, -match3);
        someMatch = 1 - someMatch;
        add(someMatch, 0);
        add(ans, (int) ((long long) 2 * someMatch% MOD));
    }
    cout << ans << "\n";
    return 0;
}