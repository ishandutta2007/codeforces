#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        bool same = true;
        int dx = 0;
        bool one = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            dx += x - a[i];
            if (a[i] == x)
                one = true;
            if (a[i] != x)
                same = false;
        }
        if (same)
        {
            cout << "0\n";
            continue;
        }
        if (dx == 0 || one)
        {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
    return 0;
}