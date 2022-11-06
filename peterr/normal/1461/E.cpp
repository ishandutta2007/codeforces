#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    k -= l;
    r -= l;
    if (x == y)
    {
        if (k + y <= r || k - x >= l)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else if (y < x)
    {
        long long last = k - y;
        long long num = (k - last + x - 1) / x;
        if (num > 0)
        {
            t -= num;
            k -= num * x;
        }
        long long days = k / (x - y);
        if (t <= days)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        long long last = r - y + 1;
        if (last - x >= 0)
        {
            cout << "Yes\n";
        }
        else
        {
            set<long long> seen;
            bool ans = true;
            while (1)
            {
                if (k >= x)
                {
                    long long num = (k - x + 1 + x - 1)/ x;
                    t -= num;
                    k -= num * x;
                }
                if (t <= 0)
                    break;
                if (seen.count(k))
                    break;
                seen.insert(k);
                if (k >= last)
                {
                    ans = false;
                    break;
                }
                k += y - x;
                t--;
            }
            if (ans)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}