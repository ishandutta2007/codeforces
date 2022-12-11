#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > 0 && a[i] % 2)
        {
            cout << (a[i] + (i1 % 2)) / 2 << endl;
            i1++;
        }
        else if (a[i] % 2)
        {
            cout << (a[i] - (i2 % 2)) / 2 << endl;
            i2++;
        }
        else
        {
            cout << a[i] / 2 << endl;
        }
    }
    return 0;
}