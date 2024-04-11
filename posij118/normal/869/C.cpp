#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int M=998244353;
    int a, b, c, mu, x, y, dp;
    cin >> a >> b >> c;

    long long int dp1[a+1][2];
    for(int i=1; i<a+1; i++){
        dp1[i][0]=i+1;
    }
    for(int i=2; i<b+1; i++){
        dp1[1][1]=i+1;
        for(int j=2; j<a+1; j++){
            dp1[j][1]=j*dp1[j-1][0]+dp1[j][0];
            dp1[j][1]%=M;
        }

        for(int j=1; j<a+1; j++){
            dp1[j][0]=dp1[j][1];
        }
    }

    long long int dp2[c+1][2];
    for(int i=1; i<c+1; i++){
        dp2[i][0]=i+1;
    }
    for(int i=2; i<b+1; i++){
        dp2[1][1]=i+1;
        for(int j=2; j<c+1; j++){
            dp2[j][1]=j*dp2[j-1][0]+dp2[j][0];
            dp2[j][1]%=M;
        }

        for(int j=1; j<c+1; j++){
            dp2[j][0]=dp2[j][1];
        }
    }

    long long int dp3[c+1][2];
    for(int i=1; i<c+1; i++){
        dp3[i][0]=i+1;
    }
    for(int i=2; i<a+1; i++){
        dp3[1][1]=i+1;
        for(int j=2; j<c+1; j++){
            dp3[j][1]=j*dp3[j-1][0]+dp3[j][0];
            dp3[j][1]%=M;
        }

        for(int j=1; j<c+1; j++){
            dp3[j][0]=dp3[j][1];
        }
    }

    cout << (((dp1[a][0]*dp2[c][0])%M)*dp3[c][0])%M;

}