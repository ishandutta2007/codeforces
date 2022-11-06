#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt += a[i];
    }
    while (q--)
    {
        int type, x;
        cin >> type >> x;
        if (type == 1)
        {
            if (a[x] == 1)
                cnt--;
            else
                cnt++;
            a[x] = 1 - a[x];
        }
        else
        {
            cout << (x <= cnt) << "\n";
        }
    }
    return 0;
}