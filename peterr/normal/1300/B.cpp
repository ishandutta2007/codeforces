#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[2 * MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; i++)
            cin >> a[i];
        sort(a, a + 2 * n);
        cout << a[n] - a[n - 1] << endl;
    }
    return 0;
}