#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    srand(clock());
    int n;
    cin >> n;
    int l = 0;
    int r = 1e9;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        cout << "> " << m << endl;
        int c;
        cin >> c;
        if (c)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    int max_el = r;
    int d = 0;
    for (int i = 0; i < 28; ++i)
    {
        cout << "? " << (rand() * 23421 + rand() + 24) % n + 1 << endl;
        int el;
        cin >> el;
        d = gcd(d, max_el - el);
    }
    cout << "! " << max_el - d * (n - 1) << " " << d << endl;
    return 0;
}