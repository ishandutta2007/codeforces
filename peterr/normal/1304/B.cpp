#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
string words[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    string first, second, pal;
    first = second = pal = "";
    for (int i = 0; i < n; i++)
    {
        bool isPal = true;
        for (int j = 0; j < m; j++)
        {
            if (words[i][j] != words[i][m - 1 - j])
                isPal = false;
        }
        if (isPal)
            pal = words[i];
        else
        {
            for (int j = i + 1; j < n; j++)
            {
                bool same = true;
                for (int k = 0; k < m; k++)
                {
                    if (words[i][k] != words[j][m - 1 - k])
                        same = false;
                }
                if (same)
                {
                    first += words[i];
                    second = words[j] + second;
                }
            }
        }
    }
    string ans = first + pal + second;
    cout << (int) ans.length() << endl;
    cout << ans << endl;
    return 0;
}