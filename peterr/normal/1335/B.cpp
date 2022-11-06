#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int ans[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            ans[i] = cur;
            cur = (cur + 1) % b;
        }
        for (int i = 0; i < n; i++)
            cout << (char) ('a' + ans[i]);
        cout << "\n";
    }
    return 0;
}