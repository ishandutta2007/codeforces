#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int dx[3] = {-1, 0, 1};
bool isLava[3][MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    long long bad = 0;
    for (int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;
        int newr = r == 1 ? 2 : 1;
        for (int j = 0; j < 3; j++)
        {
            int newc = c + dx[j];
            if (newc >= 1 && newc <= n)
            {
                if (isLava[r][c])
                {
                    if (isLava[newr][newc])
                        bad--;
                }
                else
                {
                    if (isLava[newr][newc])
                        bad++;
                }
            }
        }
        isLava[r][c] = !isLava[r][c];
        if (bad == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}