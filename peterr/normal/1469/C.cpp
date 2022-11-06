#include <bits/stdc++.h>

using namespace std;

void getNxt(int mn, int mx, int h, int k, int &lo, int &hi)
{
    lo = max(h, mn - k + 1);
    hi = min(h + k - 1, mx + k - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        bool ans = true;
        int mn;
        cin >> mn;
        int mx = mn;
        int lo, hi;
        for (int i = 1; i < n - 1; i++)
        {
            int h;
            cin >> h;
            getNxt(mn, mx, h, k, lo, hi);
            if (lo > hi)
            {
                ans = false;
            }
            mn = lo;
            mx = hi;
        }
        int last;
        cin >> last;
        getNxt(mn, mx, last, k, lo, hi);
        if (lo > hi)
            ans = false;
        if (ans)
        {
            ans = last >= lo && last <= hi;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}