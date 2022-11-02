#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, ptr, a;
    long long int k, suma, x;
    const int M=1000000007;
    cin >> n >> k;

    long long int coord[n][3];
    for(int i=0; i<n; i++){
        cin >> coord[i][0] >> coord[i][1] >> coord[i][2];
    }

    coord[n-1][1]=k;

    long long int dp[n][16][16][62];
    for(int i=0; i<n; i++){
        for(int j=0; j<16; j++){
            for(int k=0; k<16; k++){
                for(int l=0; l<62; l++){
                    dp[i][j][k][l]=0;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<coord[i][2]+1; j++){
            for(int k=0; k<coord[i][2]+1; k++){
                if(abs(j-k)<=1) dp[i][j][k][0]=1;
            }
        }
    }

    for(int l=1; l<62; l++){
        for(int i=0; i<n; i++){
            for(int j=0; j<coord[i][2]+1; j++){
                for(int k=0; k<coord[i][2]+1; k++){
                    suma=0;
                    for(int m=0; m<coord[i][2]+1; m++){
                        suma+=dp[i][j][m][l-1]*dp[i][m][k][l-1];
                        suma%=M;
                    }
                    dp[i][j][k][l]=suma;
                }
            }
        }
    }

    long long int dp2[16][6200];
    dp2[0][0]=1;
    for(int i=1; i<16; i++){
        dp2[i][0]=0;
    }

    for(int i=0; i<16; i++){
        for(int j=1; j<6200; j++){
            dp2[i][j]=0;
        }
    }

    ptr=0;
    for(int i=0; i<n; i++){
        x=coord[i][1]-coord[i][0];
        a=0;
        while(x>0){
            if(x%2==1){
                ptr++;
                for(int j=0; j<coord[i][2]+1; j++){
                    for(int k=0; k<coord[i][2]+1; k++){
                        dp2[j][ptr]+=dp2[k][ptr-1]*dp[i][k][j][a];
                        dp2[j][ptr]%=M;
                    }
                }

            }

            x/=2;
            a++;
        }
    }

    cout << dp2[0][ptr];


}