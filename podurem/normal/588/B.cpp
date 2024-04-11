#include <bits/stdc++.h>

using namespace std;

bool prek(long long x)
{
    for (long long i = 2; i < (long long) (sqrt(x) + 1); i++)
        if (x % (i * i) == 0)
            return false;
    return true;
}

int main()
{
    long long n, ans;
    cin >> n;
    bool f = 1;
    for (long long i = 1; i <= (long long) (sqrt(n) + 1); i++)
        if (n % i == 0)
        {
            if (prek(n / i))
            {
                cout << n / i;
                return 0;
            }
            if (prek(i))
                ans = i;
        }
    cout << ans;
    return 0;
}