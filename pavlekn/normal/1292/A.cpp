#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
int used[MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int ans = 0;
    for (int i = 0; i < q; ++i)
    {
        int r, c;
        cin >> c >> r;
        --c;
        if (used[r][c])
        {
            used[r][c] = false;
            if (used[r - 1][c ^ 1])
            {
                --ans;
            }
            if (used[r][c ^ 1])
            {
                --ans;
            }
            if (used[r + 1][c ^ 1])
            {
                --ans;
            }
        }
        else
        {
            used[r][c] = true;
            if (used[r - 1][c ^ 1])
            {
                ++ans;
            }
            if (used[r][c ^ 1])
            {
                ++ans;
            }
            if (used[r + 1][c ^ 1])
            {
                ++ans;
            }
        }
        if (ans == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}