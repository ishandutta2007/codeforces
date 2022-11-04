#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

bool dp[MAXN + 1][2 * MAXN + 1][3];

string str;
string sol;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    if(str[0] == 'W')
        dp[0][n + 1][0] = 1;
    if(str[0] == 'L')
        dp[0][n - 1][1] = 1;
    if(str[0] == 'D')
        dp[0][n][2] = 1;
    if(str[0] == '?') {
        dp[0][n + 1][0] = 1;
        dp[0][n - 1][1] = 1;
        dp[0][n][2] = 1;
    }
    if(n != 1 && k == 1)
        dp[0][n + 1][0] = dp[0][n + 1][1] = dp[0][n + 1][2] = dp[0][n - 1][0] = dp[0][n - 1][1] = dp[0][n - 1][2] = 0;
    for(i = 1; i < n; i++) {
        for(j = 0; j <= 2 * n; j++) {
            if(str[i] == 'W')
                if(j > 0)
                    dp[i][j][0] = (dp[i - 1][j - 1][0] | dp[i - 1][j - 1][1] | dp[i - 1][j - 1][2]);
            if(str[i] == 'L')
                if(j < 2 * n)
                    dp[i][j][1] = (dp[i - 1][j + 1][0] | dp[i - 1][j + 1][1] | dp[i - 1][j + 1][2]);
            if(str[i] == 'D')
                dp[i][j][2] = (dp[i - 1][j][0] | dp[i - 1][j][1] | dp[i - 1][j][2]);
            if(str[i] == '?') {
                if(j > 0)
                    dp[i][j][0] = (dp[i - 1][j - 1][0] | dp[i - 1][j - 1][1] | dp[i - 1][j - 1][2]);
                if(j < 2 * n)
                    dp[i][j][1] = (dp[i - 1][j + 1][0] | dp[i - 1][j + 1][1] | dp[i - 1][j + 1][2]);
                dp[i][j][2] = (dp[i - 1][j][0] | dp[i - 1][j][1] | dp[i - 1][j][2]);
            }
            if((j == n + k || j == n - k) && i < n - 1)
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 0;
        }
    }
    sol = str;
    if(dp[n - 1][k + n][0] || dp[n - 1][k + n][1] || dp[n - 1][k + n][2]) {
        int poz = n - 1;
        int dif = n + k;
        while(poz >= 0) {
            i = 0;
            while(dp[poz][dif][i] == 0)
                i++;
              //  printf("%d %d %d\n" ,poz,dif,i);
            if(i == 0) {
                dif--;
                sol[poz] = 'W';
            }
            if(i == 1) {
                dif++;
                sol[poz] = 'L';
            }
            if(i == 2)
                sol[poz] = 'D';
            poz--;
        }
        for(i = 0; i < n; i++)
            cout << sol[i];
    }
    else if(dp[n - 1][n - k][0] || dp[n - 1][n - k][1] || dp[n - 1][n - k][2]) {
        int poz = n - 1;
        int dif = n - k;
        while(poz >= 0) {
            sol[poz] = str[poz];
            i = 0;
            while(dp[poz][dif][i] == 0)
                i++;
            if(i == 0) {
                dif--;
                sol[poz] = 'W';
            }
            if(i == 1) {
                dif++;
                sol[poz] = 'L';
            }
            if(i == 2)
                sol[poz] = 'D';
            poz--;
        }
        for(i = 0; i <  n; i++)
            cout << sol[i];
    }
    else
        cout << "NO";
   // cin.close();
   // cout.close();
    return 0;
}