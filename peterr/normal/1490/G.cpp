#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
long long pref[MAXN];
long long mx[MAXN];

int getInd(int n, int x)
{
    int ans = -1;
    for (int jump = n; jump; jump >>= 1)
    {
        while (ans + jump < n && mx[ans + jump] < x)
            ans += jump;
    }
    return ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            pref[i] = a[i];
            if (i)
                pref[i] += pref[i - 1];
            mx[i] = pref[i];
            if (i)
                mx[i] = max(mx[i], mx[i - 1]);
        }
        while (m--)
        {
            int x;
            cin >> x;
            if (sum <= 0)
            {
                if (mx[n - 1] < x)
                    cout << "-1 ";
                else
                    cout << getInd(n, x) << " ";
            }
            else
            {
                int diff = (int) max(0LL, x - mx[n - 1]);
                int cycles = (int) ((diff + sum - 1) / sum);
                x -= (int) (cycles * sum);
                cout << (long long) cycles * n + getInd(n, x) << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}