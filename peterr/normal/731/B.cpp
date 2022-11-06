#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool ans = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < 0)
            ans = false;
        else if (a[i] % 2 != 0)
            a[i + 1]--;
    }
    if (a[n - 1] % 2 != 0)
        ans = false;
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}