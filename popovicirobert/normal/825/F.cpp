#include <bits/stdc++.h>
#define long long ll
#define MAXN 8000

using namespace std;

int dp[MAXN + 1];
string str;

int pi[MAXN + 1][MAXN + 1];

inline int check(int x) {
    int cnt = 0;
    while(x > 0) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

inline void prefix(int pos, int n) {
    int k = 0;
    pi[pos][pos] = 0;
    for(int i = pos + 1; i <= n; i++) {
        while(k > 0 && str[i] != str[k + 1 + pos - 1])
            k = pi[pos][k + pos - 1];
        if(str[i] == str[k + 1 + pos - 1])
            k++;
        pi[pos][i] = k;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> str;
    str.push_back(0);
    for(i = str.size() - 1; i > 0; i--)
        str[i] = str[i - 1];
    n = str.size() - 1;
    for(i = 1; i <= n; i++)
        prefix(i, n);
    for(i = 1; i <= n; i++) {
        dp[i] = n + 1;
        for(j = i - 1; j >= 0; j--) {
            if((i - j) % (i - j - pi[j + 1][i]) == 0)
               dp[i] = min(dp[i], dp[j] + check((i - j) / (i - j - pi[j + 1][i])) + i - j - pi[j + 1][i]);
            else
               dp[i] = min(dp[i], dp[j] + i - j + 1);
        }
    }
    cout << dp[n];
    //cin.close();
    //cout.close();
    return 0;
}