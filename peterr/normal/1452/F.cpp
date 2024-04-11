#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int a[MAXN];
int twopow[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    twopow[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        twopow[i] = twopow[i - 1] * 2;
    }
    int n, q;
    cin >> n >> q;
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += (long long) a[i] * twopow[i];
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos, val;
            cin >> pos >> val;
            total -= (long long) a[pos] * twopow[pos];
            a[pos] = val;
            total += (long long) a[pos] * twopow[pos];
        }
        else
        {
            int x;
            long long k;
            cin >> x >> k;
            if (k > total)
            {
                cout << "-1\n";
                continue;
            }
            long long add = 0;
            for (int i = 0; i <= x; i++)
            {
                k -= a[i];
                add += (long long) a[i] * (twopow[i] - 1);
            }
            long long ans = 0;
            int p = x + 1;
            int two = 2;
            while (k > 0 && p < n)
            {
                int num = (int) min((long long) a[p], k / two);
                k -= (long long) num * two;
                add += (long long) num * two * (twopow[x] - 1);
                ans += (long long) num * (two - 1);
                if (num < a[p])
                {
                    break;
                }
                two = two * 2;
                p++;
            }
            if (k > 0)
            {
                ans += k;
                int lb = (int) max(0LL, (k - add + twopow[x] - 1) / twopow[x]);
                int ub = (int) k;
                int leaves = 0;
                int bit = p - x - 1;
                while (leaves < lb)
                {
                    ans++;
                    if (ub & (1 << bit))
                    {
                        ans--;
                        leaves |= 1 << bit;
                    }
                    bit--;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}