#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
pair<int, int> pr[MAXN];
vector<int> a[MAXN];
long long ans[MAXN + 1];

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
        fill(ans + 1, ans + n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            a[i].clear();
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pr[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pr[i].second;
        }
        for (int i = 0; i < n; i++)
        {
            a[pr[i].first - 1].push_back(pr[i].second);
        }
        for (int i = 0; i < n; i++)
        {
            /*
            cout << "arr " << i << endl;
            for (int x : a[i])
                cout <<  "el " << x << endl;
            */
            sort(a[i].rbegin(), a[i].rend());
        }
        for (int i = 0; i < n; i++)
        {
            vector<long long> pref(a[i].size(), 0);
            if (pref.size())
                pref[0] = a[i][0];
            for (int j = 1; j < (int) pref.size(); j++)
                pref[j] = pref[j - 1] + a[i][j];
            for (int j = 1; j <= (int) pref.size(); j++)
            {
                if (j > (int) pref.size())
                    continue;
                else
                {
                    int num = (int) pref.size() / j;
                    //cout << pref[num * j - 1] << " ";
                    ans[j] += pref[num * j - 1];
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
    return 0;
}