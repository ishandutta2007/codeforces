#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
const int MAXK = 5;
const int MOD = 998244353; // = 7 * 17 * 2^4 * 2^19 + 1
const int PRIM_ROOT = 62;
const int LOGN = 19;
int a[MAXN];
int b[MAXN];
int ans[MAXN];
int queries[MAXN];
int fac[MAXN + 1];
int invFac[MAXN + 1];
int twoPow[MAXN + 1];
int rev[1 << LOGN];

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

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

const int ROOT = modpow(PRIM_ROOT, 1904);
const int ROOT_INV = modinv(ROOT);

void ntt(vector<int> &c, int root)
{
    int n = (int) c.size();
    for (int i = 0; i < n; i++)
    {
        if (i < rev[i])
            swap(c[i], c[rev[i]]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        int fund = root;
        for (int i = LOGN; !(len & (1 << i)); i--)
            fund = (int) ((long long) fund * fund % MOD);
        for (int i = 0; i < n; i += len)
        {
            int w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                int u = c[i + j];
                int v = (int) ((long long) w * c[i + j + len / 2] % MOD);
                c[i + j] = add(u, v);
                c[i + j + len / 2] = add(u, -v);
                w = (int) ((long long) w * fund % MOD);
            }
        }
    }
}

void mult(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int n = (int) a.size();
    ntt(a, ROOT);
    ntt(b, ROOT);
    for (int i = 0; i < n; i++)
    {
        res[i] = (int) ((long long) a[i] * b[i] % MOD);
    }
    ntt(res, ROOT_INV);
    int sizeInv = modinv(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = (int) ((long long) sizeInv * res[i] % MOD);
    }
}

int choose(int n, int k)
{
    if (k > n)
        return 0;
    int ans = (int) ((long long) fac[n] * invFac[k] % MOD);
    return (int) ((long long) ans * invFac[n - k] % MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < (1 << LOGN); i++)
    {
        for (int j = 0; j < LOGN; j++)
        {
            if (i & (1 << j))
                rev[i] |= 1 << (LOGN - j - 1);
        }
    }
    fac[0] = twoPow[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
        twoPow[i] = (int) ((long long) twoPow[i - 1] * 2 % MOD);
    }
    invFac[MAXN] = modinv(fac[MAXN]);
    for (int i = MAXN - 1; i >= 0; i--)
    {
        invFac[i] = (int) ((long long) invFac[i + 1] * (i + 1) % MOD);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }
    vector<int> x(1 << LOGN);
    vector<int> y(1 << LOGN);
    vector<int> res(1 << LOGN);
    for (int i = 0; i < k; i++)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        int ptr = 0;
        while (ptr < n && a[ptr] < b[i])
        {
            if (ptr + 1 < n && a[ptr + 1] == a[ptr])
                cnt2 += 2;
            else
                cnt1++;
            int cur = a[ptr];
            while (ptr < n && a[ptr] == cur)
                ptr++;
        }
        x.assign(1 << LOGN, 0);
        y.assign(1 << LOGN, 0);
        res.assign(1 << LOGN, 0);
        for (int j = 0; j <= cnt1; j++)
        {
            x[j] = (int) ((long long) choose(cnt1, j) * twoPow[j] % MOD);
        }
        for (int j = 0; j <= cnt2; j++)
        {
            y[j] = choose(cnt2, j);
        }
        mult(x, y, res);
        for (int j = 0; j < q; j++)
        {
            if (queries[j] < 2 * b[i] + 2)
                continue;
            int num = (queries[j] - 2 * b[i] - 2) / 2;
            if (num > n)
                continue;
            ans[j] = add(ans[j], res[num]);
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}