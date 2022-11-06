#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXD = 10;
double dp[MAXN + 1][MAXD];
int where[MAXN + 1][MAXD];
int which[MAXN + 1][MAXD];
int a[MAXN + 1];
double b[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = log(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][a[i] % 10] = b[i];
        which[i][a[i] % 10] = i;
        where[i][a[i] % 10] = 1;
        for (int j = 0; j < 10; j++)
        {
            if (dp[i - 1][j] > dp[i][j])
            {
                dp[i][j] = dp[i - 1][j];
                which[i][j] = which[i - 1][j];
                where[i][j] = where[i - 1][j];
            }
            int nxt = (j * a[i]) % 10;
            if (dp[i - 1][j] > 0 && dp[i - 1][j] + b[i] > dp[i][nxt])
            {
                dp[i][nxt] = dp[i - 1][j] + b[i];
                where[i][nxt] = j;
                which[i][nxt] = i;
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "dp " << i << " " << j << " " << dp[i][j] << endl;
            cout << "where " << i << " " << j << " " << where[i][j] << endl;
            cout << "which " << i << " " << j << " " << which[i][j] << endl;
        }
    }
    */
    vector<int> ans;
    int cur = n;
    while (cur > 0 && which[cur][d])
    {
        int ind = which[cur][d];
        ans.push_back(ind);
        d = where[cur][d];
        cur = ind - 1;
    }
    if (ans.empty())
    {
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << a[x] << " ";
    cout << "\n";
    return 0;
}