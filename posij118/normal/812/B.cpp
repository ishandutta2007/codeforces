#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m, a, b;
    b=0;
    cin >> n >> m;

    char bud[n][m+2];
    for(int i=0; i<n; i++){
        for(int j=0; j<m+2; j++){
            cin >> bud[i][j];
        }
    }

    int last_row;
    for(int i=0; i<n; i++){
        for(int j=0; j<m+2; j++){
            if(bud[i][j]=='1') b=1;
        }

        if(b==1){
            last_row=n-1-i;
            break;
        }
    }

    int last[n];
    for(int i=0; i<n; i++){
            a=0;
        for(int j=m+1; j>-1; j--){
            if(a==0 && bud[i][j]=='1'){
                last[i]=j;
                a=1;
            }
        }

        if(a==0) last[i]=0;
    }

    int first[n];
     for(int i=0; i<n; i++){
            a=0;
        for(int j=0; j<m+2; j++){
            if(a==0 && bud[i][j]=='1'){
                first[i]=j;
                a=1;
            }
        }

        if(a==0) first[i]=m+1;
    }

    reverse(last, last + n);
    reverse(first, first + n);



    int dp[n][2];

    dp[0][0]=2*last[0];
    dp[0][1]=m+1;

    for(int i=1; i<last_row; i++){
        dp[i][0]=min(dp[i-1][1]+m+2, dp[i-1][0]+1+2*last[i]);
        dp[i][1]=min(dp[i-1][0]+m+2, dp[i-1][1]+1+2*(m+1-first[i]));
    }

    if(last_row==0) cout << last[0];
    else if(last_row==1) cout << min(dp[0][0]+1+last[1], dp[0][1]+1+(m+1-first[1]));
    else{
        cout << min(dp[last_row-1][0]+1+last[last_row], dp[last_row-1][1]+1+(m+1-first[last_row]));
    }



}