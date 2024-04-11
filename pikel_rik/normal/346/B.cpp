#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

string s1, s2, virus;
int dp[105][105][105], memo[26][105];
int lps[100];

void constructLps(const string &pat) {
    int m = pat.length();

    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
}

int findd(char c, int i) {
    if (memo[c - 'A'][i] != -1)
        return memo[c - 'A'][i];
    if (c == virus[i] or i == 0)
        return memo[c - 'A'][i] = i;
    return memo[c - 'A'][i] = findd(c, lps[i-1]);
}

int recurse(int i, int j, int k) {
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (k >= virus.length())
        return dp[i][j][k] = -1000;
    if (i == s1.length() or j == s2.length())
        return dp[i][j][k] = 0;

    if (s1[i] == s2[j]) {
        int temp = findd(s1[i], k);
        if (s1[i] == virus[temp])
            return dp[i][j][k] = max(recurse(i + 1, j + 1, k), 1 + recurse(i + 1, j + 1, temp + 1));
        return dp[i][j][k] = 1 + recurse(i + 1, j + 1, 0);
    }
    return dp[i][j][k] = max(recurse(i + 1, j, k), recurse(i, j + 1, k));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s1 >> s2 >> virus;
    constructLps(virus);

    memset(dp, -1, sizeof(dp));
    memset(memo, -1, sizeof(memo));
    recurse(0, 0, 0);

    int i = 0, j = 0, k = 0;
    int n = s1.length(), m = s2.length(), v = virus.length();

    if (0 == dp[0][0][0]) {
        cout << "0\n";
        return 0;
    }

    string ans;
    while (i < n and j < m) {
        if (s1[i] == s2[j]) {
            int temp = findd(s1[i], k);
            if (s1[i] == virus[temp]) {
                if (dp[i + 1][j + 1][k] > 1 + dp[i + 1][j + 1][temp + 1]) {
                    i++;
                    j++;
                }
                else {
                    ans += s1[i];
                    i++; j++;
                    k = temp + 1;
                }
            }
            else {
                ans += s1[i];
                i++; j++;
                k = 0;
            }
        }
        else {
            if (dp[i + 1][j][k] > dp[i][j + 1][k])
                i++;
            else j++;
        }
    }

    cout << ans << "\n";
    return 0;
}