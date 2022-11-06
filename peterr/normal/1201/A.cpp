#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
string answers[MAXN];
int freq[MAXN][5];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> answers[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int points;
        cin >> points;
        int big = 0;
        for (int j = 0; j < n; j++)
        {
            freq[i][answers[j][i] - 'A']++;
        }
        for (int j = 0; j < 5; j++)
            big = max(big, freq[i][j]);
        ans += big * points;
    }
    cout << ans << endl;
    return 0;
}