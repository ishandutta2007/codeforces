#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ans = true;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] + sum < i)
                ans = false;
            sum = a[i] + sum - i;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}