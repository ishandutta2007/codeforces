#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN];
int ans[MAXN];

void solve(int l, int r, int num)
{
    if (l > r)
        return;
    auto it = max_element(a + l, a + r + 1);
    int ind = distance(a, it);
    ans[ind] = num;
    solve(l, ind - 1, num + 1);
    solve(ind + 1, r, num + 1);
}

int main()
{
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
        solve(0, n - 1, 0);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}