#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d, h;
    cin >> n >> d >> h;
    if (d > 2 * h)
    {
        cout << -1;
        return 0;
    }
    if (d == 1)
    {
        if (n == 2 && h == 1)
            cout << "1 2";
        else
            cout << -1;
        return 0;
    }
    for (int i = 1; i <= h; i++)
        cout << i << " " << i + 1 << endl;
    if (h < d)
        cout << "1 " << h + 2 << endl;
    for (int i = h + 2; i <= d; i++)
        cout << i << " " << i + 1 << endl;
    for (int i = d + 2; i <= n; i++)
        cout << h << " " << i << endl;
    return 0;
}