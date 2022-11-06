#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int lt[MAXN + 1][2];
int rt[MAXN + 1][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i <= n; i++)
            lt[i][0] = lt[i][1] = rt[i][0] = rt[i][1] = i;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'L')
                lt[i][0] = lt[i - 1][1];
            else
                lt[i][1] = lt[i - 1][0];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'R')
                rt[i][0] = rt[i + 1][1];
            else
                rt[i][1] = rt[i + 1][0];
        }
        for (int i = 0; i <= n; i++)
        {
            cout << rt[i][0] - lt[i][0] + 1 << " \n"[i == n];
        }
    }
    return 0;
}