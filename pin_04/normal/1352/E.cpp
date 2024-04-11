#include <bits/stdc++.h>

using namespace std;

bool flag[8005];

int a[8005];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            flag[i] = false;
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 2; j >= 0; j--)
            {
                if (a[i] - a[j] > n) break;
                flag[a[i] - a[j]] = true;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += flag[a[i] - a[i - 1]];
        }
        cout << cnt << "\n";
    }
    return 0;
}