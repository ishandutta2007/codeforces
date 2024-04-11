#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int a[MAXN];

bool isSorted(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        int ptr = 0;
        while (ptr < n && !isSorted(n))
        {
            if (a[ptr] > x)
            {
                swap(a[ptr], x);
                ans++;
            }
            ptr++;
        }
        if (!isSorted(n))
            ans = -1;
        cout << ans << "\n";
    }
    return 0;
}