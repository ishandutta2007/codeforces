#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int p[502];
int ans[502][502];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) ans[i][j] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        int x = i, y = i;
        for(int j=1;j<=p[i];j++)
        {
            ans[x][y] = p[i];
            if(y > 1 && ans[x][y-1] == 0) y--;
            else x++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}