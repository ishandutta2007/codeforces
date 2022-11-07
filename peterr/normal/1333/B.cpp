#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
int b[MAXN];

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
        int pos, neg;
        pos = neg = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
                pos++;
            else if (a[i] < 0)
                neg++;
        }
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool ans = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > 0)
                pos--;
            else if (a[i] < 0)
                neg--;
            int diff = b[i] - a[i];
            if (diff > 0 && pos == 0)
                ans = false;
            if (diff < 0 && neg == 0)
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}