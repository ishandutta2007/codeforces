#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
pair<int, int> a[MAXN];

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
            cin >> a[i].first >> a[i].second;
        }
        int pos = 0;
        int time = 0;
        int dest = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int newtime = a[i].first;
            int dx = dest > pos ? 1 : -1;
            int newpos = pos + dx * min(abs(pos - dest), newtime - time);
            if (newpos == dest)
            {
                dest = a[i].second;
                if (i < n - 1)
                    ans += a[i + 1].first - newtime >= abs(newpos - dest);
                else
                    ans++;
            }
            else
            {
                int place1 = min(newpos, dest);
                int place2 = max(newpos, dest);
                if (a[i].second >= place1 && a[i].second <= place2)
                {
                    if (i < n - 1)
                        ans += a[i + 1].first - newtime >= abs(newpos - a[i].second);
                    else
                        ans++;
                }
            }
            time = newtime;
            pos = newpos;
        }
        cout << ans << "\n";
    }
    return 0;
}