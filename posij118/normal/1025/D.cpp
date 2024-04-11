#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
    if(x < y) swap(x, y);
    if(y == 0) return x;
    else return gcd(x % y, y);
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    bool g[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            g[i][j] = 0;
            if(gcd(a[i], a[j]) > 1) g[i][j] = 1;
        }
    }

    bool dp[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            dp[i][j] = 0;
            if(i == j) dp[i][j] = 1;
        }
    }

    for(int d = 2; d <= n; d++){
        for(int i = 0; i + d <= n; i++){
            for(int j = i+1; j< i + d; j++){
                if(g[i][j]){
                    if(dp[j][i+1] && dp[j][i + d - 1]){
                        dp[i][i + d - 1] = 1;
                        break;
                    }
                }
            }

            for(int j = i; j< i + d - 1; j++){
                if(g[i + d  - 1][j]){
                    if(dp[j][i] && dp[j][i + d - 2]){
                        dp[i + d - 1][i] = 1;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(dp[i][0] && dp[i][n - 1]){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";

}