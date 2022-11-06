#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int p[MAXN];
int loc[MAXN];
bool used[MAXN];

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
            cin >> p[i];
            loc[p[i]] = i;
        }
        fill(used, used + n, false);
        int cur = 1;
        bool ans = true;
        while (ans && cur <= n)
        {
            int pos = loc[cur];
            while (pos < n && !used[pos])
            {
                if (p[pos] != cur)
                {
                    ans = false;
                    break;
                }
                cur++;
                used[pos] = true;
                pos++;
            }
        }
        if (ans)
            cout << "Yes\n";
        else
            cout <<"No\n";
    }
    return 0;
}