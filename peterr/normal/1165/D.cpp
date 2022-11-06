#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        long long* divisors = new long long[n];
        for (int j = 0; j < n; j++)
        {
            cin >> divisors[j];
        }
        sort(divisors, divisors + n);

        long long x = divisors[0] * divisors[n - 1];
        vector<long long> trueDivisors;
        for (long long d = 2; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                trueDivisors.push_back(d);
                if (d * d != x)
                    trueDivisors.push_back(x / d);
            }
        }
        sort(trueDivisors.begin(), trueDivisors.end());

        if (trueDivisors.size() != n)
            cout << -1 << endl;
        else
        {
            bool valid = true;
            for (int j = 0; j < n; j++)
            {
                if (divisors[j] != trueDivisors[j])
                {
                    valid = false;
                }
            }
            if (valid)
            {
                cout << x << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}