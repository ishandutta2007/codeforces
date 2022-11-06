#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250000;
int fac[MAXN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = (int) (((long long) fac[i - 1] * i) % m);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = (int) (((long long) fac[i] * fac[n - i + 1]) % m);
        temp = (int) (((long long) temp * (n - i + 1) % m));
        ans += temp;
        if (ans > m)
            ans -= m;
    }
    cout << ans << endl;
    return 0;
}