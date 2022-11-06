#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
long long val[MAXN];
long long suf[MAXN];
long long pref[MAXN];

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
            if (i)
                val[i] = a[i] - val[i - 1];
            else
                val[i] = a[i];
        }
        suf[n - 1] = val[n - 1];
        suf[n - 2] = val[n - 2];
        for (int i = n - 3; i >= 0; i--)
        {
            suf[i] = min(suf[i + 2], val[i]);
        }
        pref[0] = val[0];
        pref[1] = val[1];
        for (int i = 2; i < n; i++)
        {
            pref[i] = min(pref[i - 2], val[i]);
        }
        bool ans = false;
        if (suf[0] >= 0 && suf[1] >= 0 && val[n - 1] == 0)
            ans = true;
        for (int i = 1; i < n; i++)
        {
            if (i - 2 >= 0 && pref[i - 2] < 0)
                continue;
            if (i - 3 >= 0 && pref[i - 3] < 0)
                continue;
            long long prev2 = i - 2 >= 0 ? val[i - 2] : 0;
            if (a[i] - prev2 < 0)
                continue;
            if (a[i - 1] - a[i] + prev2 < 0)
                continue;
            if (i + 1 < n && suf[i + 1] + 2 * a[i] - 2 * a[i - 1] < 0)
                continue;
            if (i + 2 < n && suf[i + 2] - 2 * a[i] + 2 * a[i - 1] < 0)
                continue;
            if ((i - (n - 1)) % 2 == 0)
            {
                if (val[n - 1] - 2 * a[i] + 2 * a[i - 1] == 0)
                    ans = true;
            }
            else
            {
                if (val[n - 1] + 2 * a[i] - 2 * a[i - 1] == 0)
                    ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}