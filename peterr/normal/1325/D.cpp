#include <bits/stdc++.h>

using namespace std;

int bits[70];

int main()
{
    long long u, v;
    cin >> u >> v;
    if (u % 2 != v % 2)
        cout << -1 << endl;
    else
    {
        bool carry = 0;
        for (int i = 0; i < 63; i++)
        {
            if (!carry)
            {
                if ((u & (1LL << i)) == (v & (1LL << i)))
                {
                    bits[i] = (u & (1LL << i)) > 0;
                }
                else if ((v & (1LL << i)))
                {
                    bits[i - 1] += 2;
                }
                else
                {
                    carry = 1;
                    bits[i] = 1;
                    bits[i - 1] += 2;
                }
            }
            else
            {
                if ((u & (1LL << i)) == (v & (1LL << i)))
                {
                    bits[i] = (u & (1LL << i)) > 0;
                    bits[i - 1] += 2;
                }
                else if ((v & (1LL << i)))
                {
                    carry = 0;
                }
                else
                {
                    bits[i] = 1;
                }
            }
        }
        if (carry)
            cout << -1 << endl;
        else
        {
            int n = 0;
            for (int i = 0; i < 64; i++)
            {
                n = max(n, bits[i]);
            }
            cout << n << endl;
            long long x, s;
            x = s = 0;
            for (int i = 0; i < n; i++)
            {
                if (i > 0)
                    cout << " ";
                long long ans = 0;
                for (int j = 0; j < 64; j++)
                {
                    if (bits[j])
                    {
                        ans += 1LL << j;
                        bits[j]--;
                    }
                }
                x ^= ans;
                s += ans;
                cout << ans;
            }
            cout << endl;
        }
    }
    return 0;
}