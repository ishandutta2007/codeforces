#include <bits/stdc++.h>

using namespace std;

long long fac[21];

long long choose(int x, int k)
{
    long long ans = fac[x] / fac[k];
    return ans / fac[x - k];
}

int main()
{
    int n;
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        fac[i] = fac[i - 1] * i;
    }
    long long ans = choose(n, n / 2) / 2;
    if (n > 4)
    {
        long long ways = fac[n / 2] / (n / 2);
        ans *= ways;
        ans *= ways;
    }
    cout << ans << "\n";
    return 0;
}