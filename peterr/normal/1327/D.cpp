#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int p[MAXN + 1];
int c[MAXN + 1];
bool visited[MAXN + 1];

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
        int ans = n + 5;
        fill(visited + 1, visited + n + 1, false);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                int j = i;
                int len = 0;
                vector<int> v;
                while (!visited[j])
                {
                    v.push_back(j);
                    len++;
                    visited[j] = true;
                    j = p[j];
                }
                ans = min(ans, len);
                for (int d = len - 1; d >= 1; d--)
                {
                    if (len % d == 0)
                    {
                        for (int start = 0; start < d; start++)
                        {
                            int color = c[v[start]];
                            bool valid = true;
                            for (int k = start; k < (int) v.size(); k += d)
                            {
                                if (c[v[k]] != color)
                                {
                                    valid = false;
                                    break;
                                }
                            }
                            if (valid)
                            {
                                ans = min(ans, d);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}