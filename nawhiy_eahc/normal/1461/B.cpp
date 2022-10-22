#include <iostream>

using namespace std;
char matrix[502][502];
int dp[502][502];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            for(int j=1;j<=m;j++){
                matrix[i][j] = s[j-1];
                dp[i][j] = 0;
            }
        }
        int sum = 0;
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i == n || j == 1 || j == m){
                    if(matrix[i][j] == '*'){
                        dp[i][j] = 1; sum += dp[i][j];
                    }
                }
                else{
                    if(matrix[i][j] == '*'){
                        dp[i][j] = min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]))+1;
                        sum += dp[i][j];
                    }
                }
            }
        }

        printf("%d\n", sum);
    }
}