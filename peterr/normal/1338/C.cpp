#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int cycle = (63 - __builtin_clzll(n)) / 2;
        long long stop = 1LL << (cycle * 2);
        if (n % 3 == 1)
        {
            long long base = 1LL << (cycle * 2);
            cout << base + (n - base) / 3 << "\n";
        }
        else if (n % 3 == 2)
        {
            long long base = 0b10LL << (cycle * 2);
            long long diff = (n - (stop + 1)) / 3;
            for (int i = 0; i < cycle; i++)
            {
                long long temp = diff & (0b11LL << 2 * i);
                temp >>= 2 * i;
                if (temp == 1)
                    base += 0b10LL << (2 * i);
                else if (temp == 2)
                    base += 0b11LL << (2 * i);
                else if (temp == 3)
                    base += 0b01LL << (2 * i);
            }
            cout << base << "\n";
        }
        else if (n % 3 == 0)
        {
            long long base1 = 1LL << (cycle * 2);
            base1 = base1 + (n - 2 - base1) / 3;
            long long base2 = 0b10LL << (cycle * 2);
            long long diff = (n - 1 - (stop + 1)) / 3;
            for (int i = 0; i < cycle; i++)
            {
                long long temp = diff & (0b11LL << 2 * i);
                temp >>= 2 * i;
                if (temp == 1)
                    base2 += 0b10LL << (2 * i);
                else if (temp == 2)
                    base2 += 0b11LL << (2 * i);
                else if (temp == 3)
                    base2 += 0b01LL << (2 * i);
            }
            cout << (base1 ^ base2) << "\n";
        }
    }
    return 0;
}