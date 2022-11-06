#include <bits/stdc++.h>

using namespace std;

int query(int l, int r)
{
    if (l > r)
        swap(l, r);
    cout << "? " << l << " " << r << endl;
    int q;
    cin >> q;
    return q;
}

int main()
{
    int n;
    cin >> n;
    int p = query(1, n);
    int lo = p + 1;
    int hi = n;
    if (p == n)
    {
        lo = 1;
        hi = p - 1;
    }
    else
    {
        int temp = query(p, n);
        if (temp != p)
        {
            lo = 1;
            hi = p - 1;
        }
    }
    while (abs(lo - hi) >= 2)
    {
        int mid = (lo + hi) / 2;
        int q = query(mid, p);
        if ((q != p) ^ (mid > p))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    if (lo != hi)
    {
        int qq = query(lo, hi);
        if (qq == lo)
            cout << "! " << hi << endl;
        else
            cout << "! " << lo << endl;
        return 0;
    }
    cout << "! " << lo << endl;
    return 0;
}