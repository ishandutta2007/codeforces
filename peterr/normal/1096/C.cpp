#include <bits/stdc++.h>

using namespace std;



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int g = __gcd(180, x);
        int k = x / g;
        int temp = k;
        while (180 * k / x < k + 2)
        {
            k += temp;
        }
        cout << 180 * k / x << endl;
    }
    return 0;
}