#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
const int LOGN = 20;
int p[MAXN];
bool checkpoint[MAXN];
int bit[MAXN + 1];
int prod[LOGN + 1][MAXN + 1];
int sum[LOGN + 1][MAXN + 1];

void inc(int pos, int amt)
{
    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int findPos(int x)
{
    int ans = 0;
    for (int i = 20; i >= 0; i--)
    {
        if (ans + (1 << i) <= MAXN && bit[ans + (1 << i)] < x)
        {
            ans += 1 << i;
            x -= bit[ans];
        }
    }
    return ans + 1;
}

int solve(int l, int r)
{
    int ans = 0;
    int cur = l;
    int diff = r - l + 1;
    for (int i = 30; i >= 0; i--)
    {
        if (diff & (1 << i))
        {
            ans = (sum[i][cur] + (int) (((long long) prod[i][cur] * ans) % MOD)) % MOD;
            cur += 1 << i;
        }
    }
    return ans;
}

int modinv(int x)
{
    int ans = 1;
    int sq = x;
    int k = MOD - 2;
    for (int i = 0; i <= 30; i++)
    {
        if (k & (1 << i))
        {
            ans = (int) (((long long) ans * sq) % MOD);
        }
        sq = (int) (((long long) sq * sq) % MOD);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int hundred = modinv(100);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i] = (int) (((long long) p[i] * hundred) % MOD);
    }
    checkpoint[0] = true;
    prod[0][n] = 1;
    sum[0][n] = 0;
    for (int i = 0; i < n; i++)
    {
        prod[0][i] = sum[0][i] = modinv(p[i]);
    }
    for (int i = 1; i <= LOGN; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int second = min(n, j + (1 << (i - 1)));
            prod[i][j] = (int) (((long long) prod[i - 1][j] * prod[i - 1][second]) % MOD);
            sum[i][j] = (sum[i - 1][second] + (int) (((long long) prod[i - 1][second] * sum[i - 1][j]) % MOD)) % MOD;
        }
    }
    vector<int> ans;
    int cur = solve(0, n - 1);
    while (q--)
    {
        int u;
        cin >> u;
        int target = query(u);
        u--;
        if (checkpoint[u])
        {
            int l = findPos(target - 1) - 1;
            int r = min(n, findPos(target + 1) - 1);
            cur = (cur - solve(l, u - 1) + MOD) % MOD;
            cur = (cur - solve(u, r - 1) + MOD) % MOD;
            cur = (cur + solve(l, r - 1)) % MOD;
            inc(u + 1, -1);
        }
        else
        {
            int l = findPos(target) - 1;
            int r = min(n, findPos(target + 1) - 1);
            cur = (cur - solve(l, r - 1) + MOD) % MOD;
            cur = (cur + solve(l, u - 1)) % MOD;
            cur = (cur + solve(u, r - 1)) % MOD;
            inc(u + 1, 1);
        }
        ans.push_back(cur);
        checkpoint[u] = !checkpoint[u];
    }
    for (int i : ans)
        cout << i << "\n";
    return 0;
}