#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, cnt, x, ans;
    ans=0;
    cin >> n >> m >> k;

    char a[n][m];
    int dp[n][m+1];

    int dp2[n+1][k + 1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<k + 1; j++){
            dp2[i][j]=0;
        }
    }

    vector<int> ones[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            dp[i][j]=0;
            if(a[i][j]=='1') ones[i].push_back(j);
        }
    }

    for(int i=0; i<n; i++){
        dp[i][m]=0;
    }



    for(int i=0; i<n; i++){
        if(ones[i].size()){

        for(int j=0; j<ones[i].size(); j++){
            for(int l=0; l<=j; l++){
                dp[i][j]=max(dp[i][j], ones[i][ones[i].size()-1] - ones[i][0] - ones[i][l+ones[i].size()-j-1] + ones[i][l]);
            }

        }

        dp[i][ones[i].size()]=ones[i][ones[i].size()-1] - ones[i][0] + 1;

        }
    }



    for(int i=1; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            for(int l=0; l<k+1; l++){
                if(j+l < k+1){
                    dp2[i][j+l]=max(dp2[i][j+l], dp[i-1][j] + dp2[i-1][l]);
                }
            }
        }
    }

    x=dp2[n][k];
    for(int i=0; i<n; i++){
        if(ones[i].size()){
        ans+=ones[i][ones[i].size()-1]-ones[i][0] + 1;
        }
    }

   


    cout << ans-x;



}