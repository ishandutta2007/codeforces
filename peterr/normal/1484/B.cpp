#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n <= 2)
        {
            cout << "0\n";
            continue;
        }
        bool valid = true;
        bool zero = false;
        int inc = -1;
        int dec = -1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > 0)
            {
                if (inc == -1)
                    inc = a[i] - a[i - 1];
                else if (inc != a[i] - a[i - 1])
                    valid = false;
            }
            else if (a[i] - a[i - 1] < 0)
            {
                if (dec == -1)
                    dec = a[i - 1] - a[i];
                else if (dec != a[i - 1] - a[i])
                    valid = false;
            }
            else
            {
                zero = true;
            }
        }
        if (zero && (inc != -1 || dec != -1))
            valid = false;
        if (!valid)
        {
            cout << "-1\n";
            continue;
        }
        if (zero)
        {
            cout << "0\n";
            continue;
        }
        if (inc == -1 || dec == -1)
        {
            cout << "0\n";
            continue;
        }
        int m = inc + dec;
        int cur = a[0];
        valid = a[0] < m;
        for (int i = 1; i < n; i++)
        {
            cur = (cur + inc) % m;
            if (cur != a[i] || a[i] >= m)
                valid = false;
        }
        if (!valid)
        {
            cout << "-1\n";
            continue;
        }
        cout << m << " " << inc << "\n";
    }
    return 0;
}