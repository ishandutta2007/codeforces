#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> lt[MAXN];
pair<int, int> rt[MAXN];

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
            cin >> lt[i].first >> lt[i].second;
            rt[i].first = lt[i].second;
            rt[i].second = lt[i].first;
        }
        sort(lt, lt + n);
        sort(rt, rt + n);
        int ans = n - 1;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> pr = lt[i];
            int cost = 0;
            int ind = -1;
            for (int jump = n; jump; jump >>= 1)
            {
                while (ind + jump < n && lt[ind + jump].first <= pr.second)
                    ind += jump;
            }
            cost += n - ind - 1;
            ind = -1;
            for (int jump = n; jump; jump >>= 1)
            {
                while (ind + jump < n && rt[ind + jump].first < pr.first)
                    ind += jump;
            }
            cost += ind + 1;
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    return 0;
}