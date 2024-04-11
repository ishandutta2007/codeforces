#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = (int) ((long long) ans * i % MOD);
    }
    int ex = 1;
    for (int i = 0; i < n - 1; i++)
    {
        ex = (int) ((long long) ex * 2 % MOD);
    }
    ans = (ans - ex + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}