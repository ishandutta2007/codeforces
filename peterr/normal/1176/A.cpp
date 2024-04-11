#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long n;
        cin >> n;
        int ops = 0;

        while (n > 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n = 2 * n / 3;
            else if (n % 5 == 0)
                n = 4 * n / 5;
            else
            {
                ops = -1;
                break;
            }
            ops++;
        }
        cout << ops << endl;

    }
    return 0;
}