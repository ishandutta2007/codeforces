#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int MOD = 1E9 + 7;
const int LOGN = 31;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int fac = 1;
        for (int i = 2; i <= n - 2; i++)
            fac = (int) ((long long) fac * i % MOD);
        int mask = (1 << 30) - 1;
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mask = mask & a[i];
            freq[a[i]]++;
        }
        int ans = 0;
        for (auto it : freq)
        {
            int num = it.first;
            int cnt = it.second;
            if (cnt <= 1 || (num & mask) != num)
                continue;
            int temp = (int) ((long long) cnt * (cnt - 1) % MOD);
            temp = (int) ((long long) temp * fac % MOD);
            ans += temp;
            if (ans >= MOD)
                ans -= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}