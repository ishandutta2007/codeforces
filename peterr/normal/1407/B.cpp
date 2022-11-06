#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
int a[MAXN];
int ans[MAXN];
bool visited[MAXN];

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
        fill(visited, visited + n, false);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        ans[0] = a[n - 1];
        visited[n - 1] = true;
        int g = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            int mx = 0;
            int ind = 0;
            for (int j = 0; j < n; j++)
            {
                if (visited[j])
                    continue;
                int gcd = __gcd(g, a[j]);
                if (gcd > mx)
                {
                    mx = gcd;
                    ind = j;
                }
            }
            visited[ind] = true;
            ans[i] = a[ind];
            g = mx;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}