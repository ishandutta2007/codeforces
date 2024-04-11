#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    if (n == 1)
    {
        cout << "! 1" << endl;
        return 0;
    }
    cout << "? 1" << endl;
    int val;
    cin >> val;
    a[0] = val;
    cout << "? 2" << endl;
    cin >> val;
    a[1] = val;
    cout << "? " << n << endl;
    cin >> val;
    a[n - 1] = val;
    cout << "? " << n - 1 << endl;
    cin >> val;
    a[n - 2] = val;
    if (a[0] < a[1])
    {
        cout << "! " << 1 << endl;
        return 0;
    }
    if (a[n - 1] < a[n - 2])
    {
        cout << "! " << n << endl;
        return 0;
    }
    int l = 0;
    int r = n - 1;
    while (r - l > 1)
    {
        int med = (l + r) / 2;
        cout << "? " << med + 1 << endl;
        cin >> val;
        a[med] = val;
        cout << "? " << med + 2 << endl;
        cin >> val;
        a[med + 1] = val;
        if (a[med] < a[med + 1])
        {
            r = med;
        }
        else
        {
            l = med;
        }
    }
    cout << "! " << r + 1 << endl;
    return 0;
}