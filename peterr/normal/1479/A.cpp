#include <bits/stdc++.h>

using namespace std;

int query(int x, int n)
{
    if (x <= 0 || x > n)
        return n + 1;
    cout << "? " << x << endl;
    int q;
    cin >> q;
    return q;
}

int main()
{
    int n;
    cin >> n;
    int lo = 0;
    int hi = n + 1;
    while (1)
    {
        int mid = (lo + hi) / 2;
        int a = query(mid - 1, n);
        int b = query(mid, n);
        int c = query(mid + 1, n);
        if (a < b)
        {
            hi = mid;
        }
        else if (c < b)
        {
            lo = mid;
        }
        else
        {
            cout << "! " << mid << endl;
            break;
        }
    }
    return 0;
}