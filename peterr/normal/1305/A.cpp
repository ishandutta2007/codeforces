#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];
int b[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i= 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; i++)
            cout << b[i] << " \n"[i == n - 1];
    }
    return 0;
}