#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> days[MAXN];
int ans[MAXN];
int freq[MAXN + 1];

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
        fill(freq + 1, freq + n + 1, 0);
        int big = 1;
        for (int i = 0; i < m; i++)
        {
            days[i].clear();
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                days[i].push_back(x);
            }
            ans[i] = days[i].back();
            freq[ans[i]]++;
            if (freq[ans[i]] > freq[big])
                big = ans[i];
        }
        for (int i = 0; i < m; i++)
        {
            if (freq[big] <= (m + 1) / 2 || days[i].back() != big || days[i].size() == 1)
                continue;
            ans[i] = days[i][0];
            freq[big]--;
        }
        if (freq[big] <= (m + 1) / 2)
        {
            cout << "YES\n";
            for (int i = 0; i < m; i++)
                cout << ans[i] << " \n"[i == m - 1];
        }
        else
            cout << "NO\n";
    }
    return 0;
}