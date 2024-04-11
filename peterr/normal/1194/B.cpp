#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5 * 1E4;
const int MAXM = 5 * 1E4;
unordered_set<int> isWhite;
int rowCost[MAXN];
int colCost[MAXM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if (c == '*')
                {
                }
                else
                {
                    rowCost[i]++;
                    colCost[j]++;
                    isWhite.insert(i * m + j);
                }
            }
        }
        int ans = 1E6;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = min(ans, rowCost[i] + colCost[j] - (isWhite.find(i * m + j) != isWhite.end() ? 1 : 0));
            }
        }
        cout << ans << endl;
        fill(rowCost, rowCost + n, 0);
        fill(colCost, colCost + m, 0);
        isWhite.clear();
    }
    return 0;
}