#include <iostream>
#include <string>

using namespace std;
int dp[5002][5002];

int main()
{
    int n, m;
    string c;
    string d;
    scanf("%d %d", &n, &m);
    cin >> c >> d;
    for(int i=0;i<=5000;i++){
        dp[0][i] = dp[i][0] = 0;
    }

    int M = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i-1] == d[j-1]){
                dp[i][j] = max(2+dp[i-1][j-1], max(dp[i][j-1], dp[i-1][j])-1);
                M = max(M, dp[i][j]);
            }
            else{
                dp[i][j] = max(0, max(dp[i][j-1], dp[i-1][j])-1);
                M = max(M, dp[i][j]);
            }
        }
    }

    printf("%d", M);
}