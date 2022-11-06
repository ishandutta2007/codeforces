#include <iostream>

using namespace std;

int possible(long long a, long long b, long long m)
{
    if (a == b)
        return 1;
    long long i = 0;
    while ((1LL << i) * (a + m) < b)
        i++;

    if ((1LL << i) * (a + 1) <= b )
        return i + 2;
    return -1;
}

int main()
{
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        long long a, b, m;
        cin >> a >> b >> m;
        int k = possible(a, b, m);
        if (k == -1)
        {
            cout << -1 << endl;
        }
        else if (k == 0)
        {
            cout << 1 << " " << a << endl;
        }
        else
        {
            long long sum = (1LL << (k - 2)) * (a + 1);
            long long* r = new long long[k + 1];
            fill(r, r + k + 1, 1);
            for (int i = 2; i <= k-1; i++)
            {
                for (long long jump = m / 2; jump > 0; jump /= 2)
                {
                    while (r[i] + jump <= m && sum + jump * (1LL << (k - i - 1)) <= b)
                    {
                        r[i] += jump;
                        sum += jump * (1LL << (k - i - 1));
                    }
                }
            }
            r[k] += b - sum;

            long long count = a;
            cout << k << " " << a << " ";
            for (int i = 2; i <= k; i++)
            {
                cout << count + r[i] << " ";
                count += count + r[i];
            }
            cout << endl;
        }
    }
    return 0;
}