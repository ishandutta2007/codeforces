#include <iostream>
#include <algorithm>

using namespace std;

const long long MOD = 998244353;

int main()
{
    long long n;
    cin >> n;
    long long* a = new long long[n+1];
    long long* b = new long long[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    long long* contribution = new long long[n + 1];

    for (long long i = 1; i <= n; i++)
    {
        contribution[i] = i * (n - i + 1) * a[i];
    }

    sort(contribution + 1, contribution + n + 1);
    sort(b + 1, b + n + 1);
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = (res + (contribution[i] % MOD) * (b[n - i + 1] % MOD)) % MOD;
    }
    cout << res;

    return 0;
}