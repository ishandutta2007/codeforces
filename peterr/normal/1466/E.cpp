#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 5E5;
const int LOGX = 60;
int freq[LOGX];
long long a[MAXN];
int twopow[LOGX];

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    twopow[0] = 1;
    for (int i = 1; i < LOGX; i++)
        twopow[i] = (int) ((long long) twopow[i - 1] * 2 % MOD);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(freq, freq + LOGX, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < LOGX; j++)
            {
                if (!(a[i] & (1LL << j)))
                    continue;
                freq[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < LOGX; j++)
            {
                if (a[i] & (1LL << j))
                {
                    add(sum1, (int) ((long long) twopow[j] * freq[j] % MOD));
                    add(sum2, (int) ((long long) twopow[j] * n % MOD));
                }
                else
                {
                    add(sum2, (int) ((long long) twopow[j] * freq[j] % MOD));
                }
            }
            add(ans, (int) ((long long) sum1 * sum2 % MOD));
        }
        cout << ans << "\n";
    }
    return 0;
}