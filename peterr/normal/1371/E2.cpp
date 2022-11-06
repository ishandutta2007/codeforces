#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];

bool check(int n, int p, int x)
{
    int big = 1;
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        while (ptr < n && a[ptr] <= x + i)
            ptr++;
        big = max(big, ptr - i);
    }
    return big < p;
}

int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int low = 1;
    for (int i = 0; i < n; i++)
    {
        low = max(low, a[i] - i);
    }
    int hi = low - 1;
    for (int jump = a[n - 1]; jump; jump >>= 1)
    {
        while (hi + jump < a[n - 1] && check(n, p, hi + jump))
            hi += jump;
    }
    cout << hi - low + 1 << "\n";
    for (int i = low; i <= hi; i++)
    {
        cout << i << " \n"[i == hi];
    }
    return 0;
}