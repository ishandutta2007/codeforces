#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector <int> a(n);
        for (int &x : a)
            cin >> x;

        sort(a.begin(), a.end());
        if (a[0] + a[1] <= d || *max_element(a.begin(), a.end()) <= d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}