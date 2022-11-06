#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, k;
    cin >> n >> t >> k;
    if (k == 1)
    {
        cout << "? 1 1" << endl;
        int q;
        cin >> q;
        if (q == 0)
        {
            cout << "! 1" << endl;
            return 0;
        }
    }
    int lo = 1;
    int hi = n;
    while (hi > lo)
    {
        int mid = (lo + hi + 1) / 2;
        cout << "? " << 1 << " " << mid << endl;
        int q;
        cin >> q;
        int len = mid;
        int zeros = len - q;
        if (zeros < k)
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << "! " << lo + 1 << endl;
    return 0;
}