#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1000;
int fac[MAXN + 1];
int a[MAXN];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        e >>= 1;
        b = (int) ((long long) b * b % MOD);
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int choose(int n, int k)
{
    int ans = (int) ((long long) fac[n] * modinv(fac[k]) % MOD);
    return (int) ((long long) ans * modinv(fac[n - k]) % MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fac[i] = (int) ((long long) fac[i - 1] * i % MOD);
    //cout << fac[2] << endl;
    //cout << modinv(2) << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        sort(a, a + n);
        int num = a[n - k];
        int cnt = 0;
        int ptr = n - k;
        while (ptr < n && a[ptr] == num)
        {
            cnt++;
            ptr++;
        }
        cout << choose(freq[num], cnt) << "\n";
    }
    return 0;
}