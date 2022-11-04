#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

string str;
string sol;

int dp[MAXN + 1][26];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, k;
    ios::sync_with_stdio(false);
    cin >> str;
    for(i = 1; i <= str.size(); i++) {
        for(j = 0; j < 26; j++) {
          dp[i][j] = str.size();
          int c = 1;
          if(j + 'a' == str[i - 1])
             c = 0;
          for(k = 0; k < 26; k++)
            if(k != j)
             dp[i][j] = min(dp[i][j], dp[i - 1][k] + c);
        }
    }
    int ans = str.size(), let;
    for(i = 0; i < 26; i++) {
        ans = min(ans, dp[str.size()][i]);
        if(ans == dp[str.size()][i])
            let = i;
    }
    i = str.size();
    while(i > 0) {
        sol.push_back(let + 'a');
        if(i > 1)
           for(j = 0; j < 26; j++)
             if(let != j && dp[i - 1][j] + (str[i - 1] != let + 'a') == dp[i][let]) {
                let = j;
                break;
             }
        i--;
    }
    while(!sol.empty()) {
        cout << sol.back();
        sol.pop_back();
    }
   // cin.close();
    //cout.close();
    return 0;
}