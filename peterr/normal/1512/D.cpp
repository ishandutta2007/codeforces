#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 2];

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
        long long sum = 0;
        for (int i = 0; i < n + 2; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n + 2);
        bool found = false;
        vector<int> ans;
        for (int i = 0; i < n + 1; i++)
        {
            if (sum - a[i] - a[n + 1] == a[n + 1])
            {
                for (int j = 0; j < n + 1; j++)
                {
                    if (i == j)
                        continue;
                    ans.push_back(a[j]);
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            if (sum - a[n + 1] - a[n] == a[n])
            {
                found = true;
                for (int j = 0; j < n; j++)
                    ans.push_back(a[j]);
            }
        }
        if (!found)
            cout << "-1\n";
        else
        {
            for (int x : ans)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}