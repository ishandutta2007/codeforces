#include <bits/stdc++.h>

using namespace std;

struct Hash
{
    int h1 = 0, h2 = 0, h3 = 0;

    bool operator==(const Hash &otherHash) const
    {
        return h1 == otherHash.h1 && h2 == otherHash.h2 && h3 == otherHash.h3;
    }
};

const int M1 = (int) 1E9 + 7;
const int M2 = (int) 1E9 + 9;
const int M3 = (int) 1E9 + 21;
const int MOD = (int) 1E9 + 7;
const int LEN = (int) 3E6;
const int ALPHA = 3;
const int MAXM = 3000;
char s[MAXM];
int dp[MAXM + 1][MAXM + 1];
string bads[4] = {"0011", "0101", "1110", "1111"};
Hash hashes[MAXM];
vector<Hash> table[LEN];

bool isOk(int startIndex)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (s[startIndex + j] != bads[i][j])
                break;
            if (j == 3)
                return false;
        }
    }
    return true;
}

bool cont(Hash &h)
{
    int index = h.h1 % LEN;
    for (Hash otherHash : table[index])
    {
        if (h == otherHash)
            return true;
    }
    return false;
}

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
        dp[i][i] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            if (j - 1 >= i)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            if (j - 2 >= i)
                dp[i][j] = (dp[i][j] + dp[i][j - 2]) % MOD;
            if (j - 3 >= i)
                dp[i][j] = (dp[i][j] + dp[i][j - 3]) % MOD;
            if (j - 4 >= i && isOk(j - 4))
                dp[i][j] = (dp[i][j] + dp[i][j - 4]) % MOD;
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    int ans = 0;
    stringstream ss;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            hashes[j].h1 = (int) (((long long) hashes[j].h1 * ALPHA + (s[i] - '0' + 1)) % M1);
            hashes[j].h2 = (int) (((long long) hashes[j].h2 * ALPHA + (s[i] - '0' + 1)) % M2);
            hashes[j].h3 = (int) (((long long) hashes[j].h3 * ALPHA + (s[i] - '0' + 1)) % M3);
            int index = hashes[j].h1 % LEN;
            if (!cont(hashes[j]))
            {
                table[index].push_back(hashes[j]);
                ans = (ans + dp[j][i + 1]) % MOD;
            }
        }
        ss << ans << endl;
    }
    cout << ss.str();
    return 0;
}