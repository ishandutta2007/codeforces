#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN];

bool isBad(int ind, int n)
{
    if (ind == 0 || ind == n - 1)
        return false;
    return a[ind] > max(a[ind + 1], a[ind - 1]) || a[ind] < min(a[ind + 1], a[ind - 1]);
}

int solve(int n)
{
    int base = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > max(a[i - 1], a[i + 1]))
            base++;
        else if (a[i] < min(a[i - 1], a[i + 1]))
            base++;
    }
    int ans = base;
    if (n >= 3)
    {
        if (isBad(1, n))
            ans = min(ans, base - 1);
        if (isBad(n - 2, n))
            ans = min(ans, base - 1);
    }
    for (int i = 1; i < n - 1; i++)
    {
        int offset = 0;
        if (isBad(i, n))
            offset--;
        if (isBad(i - 1, n))
            offset--;
        if (isBad(i + 1, n))
        {
            int temp = a[i];
            a[i] = a[i - 1];
            if (!isBad(i + 1, n))
                offset--;
            a[i] = temp;
        }
        else
        {
            int temp = a[i];
            a[i] = a[i - 1];
            if (isBad(i + 1, n))
                offset++;
            a[i] = temp;
        }
        ans = min(ans, base + offset);
    }
    return ans;
}

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
        int ans = solve(n);
        reverse(a, a + n);
        ans = min(ans, solve(n));
        cout << ans << "\n";
    }
    return 0;
}