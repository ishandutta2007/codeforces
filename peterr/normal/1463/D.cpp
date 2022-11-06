#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
bool seen[2 * MAXN + 1];

bool check(int n, int x)
{
    int ptr = 2 * n;
    for (int i = x - 1; i >= 0; i--)
    {
        while (ptr >= 1 && seen[ptr])
            ptr--;
        if (ptr < a[i])
            return false;
        ptr--;
    }
    for (int i = 0; i < n - x; i++)
    {
        int ind = n - i - 1;
        while (ptr >= 1 && seen[ptr])
            ptr--;
        if (ptr > a[ind])
            return false;
        ptr--;
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
        int n;
        cin >> n;
        fill(seen + 1, seen + 2 * n + 1, false);
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= n)
                x++;
            seen[a[i]] = true;
        }
        int lb = x;
        for (int jump = n; jump; jump >>= 1)
        {
            while (lb - jump >= 0 && check(n, lb - jump))
                lb -= jump;
        }
        int ub = x;
        for (int jump = n; jump; jump >>= 1)
        {
            while (ub + jump <= n && check(n, ub + jump))
                ub += jump;
        }
        cout << ub - lb + 1 << "\n";
    }
    return 0;
}