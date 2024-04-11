#include <bits/stdc++.h>

using namespace std;

int dp[251][251][251];

void relax(string* rel, int target, int i, int j, int** nextOcc)
{
    string r = rel[target];

    if (target == 0)
    {
        int best = nextOcc[r[r.length() - 1] - 'a'][dp[r.length() - 1][i][j]] + 1;
        if (i > 0 && rel[1].size() >= i)
            best = min(best, nextOcc[rel[1][i - 1] - 'a'][dp[r.length()][i-1][j]] + 1);
        if (j > 0 && rel[2].size() >= j)
            best = min(best, nextOcc[rel[2][j - 1] - 'a'][dp[r.length()][i][j-1]] + 1);
        dp[r.length()][i][j] = best;
    }
    else if (target == 1)
    {
        int best = nextOcc[r[r.length() - 1] - 'a'][dp[i][r.length() - 1][j]] + 1;
        if (i > 0 && rel[0].size() >= i)
            best = min(best, nextOcc[rel[0][i - 1] - 'a'][dp[i-1][r.length()][j]] + 1);
        if (j > 0 && rel[2].size() >= j)
            best = min(best, nextOcc[rel[2][j - 1] - 'a'][dp[i][r.length()][j-1]] + 1);
        dp[i][r.length()][j] = best;
    }
    else
    {
        int best = nextOcc[r[r.length() - 1] - 'a'][dp[i][j][r.length() - 1]] + 1;
        if (i > 0 && rel[0].size() >= i)
            best = min(best, nextOcc[rel[0][i - 1] - 'a'][dp[i-1][j][r.length()]] + 1);
        if (j > 0 && rel[1].size() >= j)
            best = min(best, nextOcc[rel[1][j - 1] - 'a'][dp[i][j-1][r.length()]] + 1);
        dp[i][j][r.length()] = best;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    string s;
    cin >> n >> q >> s;
    int** nextOcc = new int*[26];
    for (int i = 0; i < 26; i++)
    {
        nextOcc[i] = new int[n+2];
        nextOcc[i][n] = n;
        nextOcc[i][n+1] = n;
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if (s[j] == 'a' + i)
            {
                nextOcc[i][j] = j;
            }
            else
            {
                nextOcc[i][j] = nextOcc[i][j+1];
            }
        }
    }

    /*
    int*** dp = new int**[251];
    for (int i = 0; i < 251; i++)
    {
        dp[i] = new int*[251];
        for (int j = 0; j < 251; j++)
        {
            dp[i][j] = new int[251];
            for (int k = 0; k < 251; k++)
            {
                //dp[i][j][k] = 0;
            }
        }
    }
    */
    dp[0][0][0] = 0;

    string rel[3];
    for (int i = 0; i < 3; i++)
        rel[i] = "";
    while (q-- > 0)
    {
        char c;
        int r;
        cin >> c >> r;
        r--;
        if (c == '+')
        {
            char append;
            cin >> append;
            rel[r] += append;
            int bound1 = r == 0 ? rel[1].length() : rel[0].length();
            int bound2 = r == 2 ? rel[1].length() : rel[2].length();
            for (int i = 0; i <= bound1; i++)
            {
                for (int j = 0; j <= bound2; j++)
                {
                    relax(rel, r, i, j, nextOcc);
                }
            }
        }
        else
        {
            rel[r] = rel[r].substr(0, rel[r].length() - 1);
        }

        if (dp[rel[0].length()][rel[1].length()][rel[2].length()] > n)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}