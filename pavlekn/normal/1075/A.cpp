#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int n;
    int x, y;
    cin >> n;
    cin >> x >> y;
    if (max(x - 1, y - 1) > max(n - x, n - y))
    {
        cout << "Black" << endl;
    }
    else
    {
        cout << "White" << endl;
    }
    return 0;
}