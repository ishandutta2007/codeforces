#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int v[402][402];
int p[402][402];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            string s; cin >> s;
            for(int j=0;j<m;j++) v[i][j+1] = s[j] - '0';
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                p[i][j] = v[i][j] + p[i][j-1];
            }
        }

        int ans = 20;
        for(int i=1;i<=m;i++)
        {
            for(int j=i+3;j<=m;j++)
            {
                int cost = (j-i-1) - (p[1][j-1] - p[1][i]);
                cost += (j-i-1) - (p[5][j-1] - p[5][i]);
                for(int k=2;k<=4;k++) cost += 2 - v[k][i] - v[k][j];
                for(int k=2;k<=4;k++) cost += p[k][j-1] - p[k][i];
                ans = min(ans, cost);
                int ps = 0, Mps = 0;
                for(int k=6;k<=n;k++)
                {
                    cost += 2 - v[k-1][i] - v[k-1][j];
                    cost += 2 * (p[k-1][j-1] - p[k-1][i]) - (j-i-1);
                    cost += (j-i-1) - (p[k][j-1] - p[k][i]);

                    ps -= 2 - v[k-4][i] - v[k-4][j];
                    ps -= (j-i-1) - (p[k-5][j-1] - p[k-5][i]);
                    ps += (j-i-1) - 2 * (p[k-4][j-1] - p[k-4][i]);
                    Mps = min(Mps, ps);
                    ans = min(ans, cost + Mps);
                }
            }
        }
        cout << ans << "\n";
    }
}