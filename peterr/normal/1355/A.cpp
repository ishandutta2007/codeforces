#include <bits/stdc++.h>

using namespace std;

void gett(long long a, int &small, int &big)
{
    small = 10;
    big = -1;
    while (a)
    {
        int dig = (int) (a % 10);
        a /= 10;
        big = max(big, dig);
        small = min(small, dig);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, k;
        cin >> a >> k;
        k--;
        int big = 10;
        int small = -1;
        while (small != 0 && k)
        {
            k--;
            gett(a, small, big);
            a += small * big;
        }
        cout << a << "\n";
    }
    return 0;
}