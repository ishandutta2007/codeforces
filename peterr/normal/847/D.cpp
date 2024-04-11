#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int t[MAXN + 1];
pair<int, bool> events[2 * MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxt;
    cin >> n >> maxt;
    int ind = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        int start = max(0, t[i] - i);
        int end = maxt - i;
        if (end > start)
        {
            events[ind++] = make_pair(start, 1);
            events[ind++] = make_pair(end, 0);
        }
    }
    sort(events, events + ind);
    int ans = 0;
    int p = 0;
    int bal = 0;
    while (p < ind)
    {
        int curt = events[p].first;
        while (p < ind && events[p].first == curt)
        {
            if (events[p].second)
            {
                bal++;
            }
            else
            {
                bal--;
            }
            p++;
        }
        ans = max(ans, bal);
    }
    cout << ans << endl;
    return 0;
}