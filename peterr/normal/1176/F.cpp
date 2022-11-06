#include <bits/stdc++.h>

using namespace std;

const long long NEG = -1e15;
const int MAXN = 2 * 1e5;
vector<long long> cards[MAXN][4];
long long dp[MAXN][10];

long long maxDam(int turn, int numCards, int penNib)
{
    if (numCards == 3)
    {
        if (cards[turn][1].size() < 3)
        {
            return NEG;
        }
        else
        {
            if (penNib >= 7)
            {
                return 2 * cards[turn][1][0] + cards[turn][1][1] + cards[turn][1][2];
            }
            else
            {
                return cards[turn][1][0] + cards[turn][1][1] + cards[turn][1][2];
            }
        }
    }
    else if (numCards == 2)
    {
        long long best = NEG;
        if (cards[turn][1].size() >= 2)
        {
            if (penNib >= 8)
            {
                best = max(best, (long long) 2 * cards[turn][1][0] + cards[turn][1][1]);
            }
            else
            {
                best = max(best, (long long) cards[turn][1][0] + cards[turn][1][1]);
            }
        }
        if (cards[turn][2].size() >= 1 && cards[turn][1].size() >= 1)
        {
            int d1 = cards[turn][2][0];
            int d2 = cards[turn][1][0];
            if (d1 < d2)
                swap(d1, d2);
            if (penNib >= 8)
            {
                best = max(best, (long long) 2 * d1 + d2);
            }
            else
            {
                best = max(best, (long long) d1 + d2);
            }
        }
        return best;
    }
    else
    {
        long long best = NEG;
        if (cards[turn][1].size() >= 1)
            best = max(best, (long long) cards[turn][1][0]);
        if (cards[turn][2].size() >= 1)
            best = max(best, (long long) cards[turn][2][0]);
        if (cards[turn][3].size() >= 1)
            best = max(best, (long long) cards[turn][3][0]);
        if (penNib >= 9)
            return best * 2;
        return best;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int c, d;
            cin >> c >> d;
            cards[i][c].push_back(d);
        }
        sort(cards[i][1].rbegin(), cards[i][1].rend());
        sort(cards[i][2].rbegin(), cards[i][2].rend());
        sort(cards[i][3].rbegin(), cards[i][3].rend());
    }

    dp[0][0] = 0;
    dp[0][1] = maxDam(0, 1, 0);
    dp[0][2] = maxDam(0, 2, 0);
    dp[0][3] = maxDam(0, 3, 0);
    for (int i = 4; i < 10; i++)
        dp[0][i] = NEG;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (dp[i-1][(j + 9) % 10] >= 0 && maxDam(i, 1, (j + 9) % 10) >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][(j + 9) % 10] + maxDam(i, 1, (j + 9) % 10));
            if (dp[i-1][(j + 8) % 10] >= 0 && maxDam(i, 2, (j + 8) % 10) >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][(j + 8) % 10] + maxDam(i, 2, (j + 8) % 10));
            if (dp[i-1][(j + 7) % 10] >= 0 && maxDam(i, 3, (j + 7) % 10) >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][(j + 7) % 10] + maxDam(i, 3, (j + 7) % 10));
        }
    }
    cout << *max_element(dp[n-1], dp[n-1] + 10);
    return 0;
}