#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n,m;
int dp[50][50];
int curo = 1;int curp = 2;

int main(){
    scanf("%d",&n);
    int cnt = 1;
    int x = 2;
    for(int i = 0;i<n;i++) {
        if(cnt > n) {x = -2;cnt-=4;}

        for(int j = (n-cnt)/2;j<cnt+(n-cnt)/2;j++){
            dp[i][j] = curo;
            curo+=2;
        }

         cnt+=x;

    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){

            if(dp[i][j] == 0){ dp[i][j] = curp;
            curp+=2;}
            printf("%d ",dp[i][j]);

        }
        printf("\n");
    }
}