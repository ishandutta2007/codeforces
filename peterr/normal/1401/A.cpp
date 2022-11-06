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
        int n, k;
        cin >> n >> k;
        if (n == k)
        {
            cout << "0\n";
            continue;
        }
        if (k > n)
        {
            cout << k - n << "\n";
            continue;
        }
        if (k % 2 == n % 2)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}