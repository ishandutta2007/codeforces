#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
bool book[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int left = -1;
        int right = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> book[i];
            if (book[i])
            {
                if (left == -1)
                    left = i;
                right = i;
            }
        }
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            if (!book[i])
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}