#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 100;

int v[MAXN + 1];

int dp[MAXN + 1][2];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    dp[0][0] = 1;
    for(i = 1; i <= n; i++) {
        if(v[i] % 2 == 1) {
            for(j = i - 1; j >= 0; j--) {
                if(v[j + 1] % 2 == 1 && (i - j) % 2 == 1)
                   for(int k = 0; k < 2; k++)
                      dp[i][k] |= dp[j][k ^ 1];
            }
        }
    }
    if(dp[n][1] == 1)
        cout << "Yes";
    else
        cout << "No";
    //cin.close();
    //cout.close();
    return 0;
}