#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = n;
        vector<int> v;
        for (int i = 2; i * i <= k; i++)
        {
            while (n % i == 0)
            {
                n /= i;
                v.push_back(i);
            }
        }
        if (n > 1)
            v.push_back(n);
        if (v.empty())
        {
            cout << "NO" << endl;
        }
        else
        {
            int a, b, c;
            a = b = c = 1;
            int ptr = 1;
            a = v[0];
            while (ptr < (int) v.size() && (b == 1 || b == a))
            {
                b *= v[ptr];
                ptr++;
            }
            while (ptr < (int) v.size())
            {
                c *= v[ptr];
                ptr++;
            }
            if (b > 1 && c > 1 && a != b && b != c && c != a)
            {
                cout << "YES" << endl;
                cout << a << " " << b << " " << c << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}