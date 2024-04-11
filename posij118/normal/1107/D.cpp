#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, pref, flag;
    cin >> n;

    char comp[n][n/4];
    bool matrix[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n/4; j++){
            cin >> comp[i][j];
            if(comp[i][j] < 'G' && comp[i][j] >= 'A'){
                x = 10 + comp[i][j] - 'A';
            }
            else x = comp[i][j] - '0';

            for(int k = 0; k<4; k++){
                matrix[i][4*j + k] = (x & (1 << (3 - k)));
            }
        }
    }

    int p[n + 1][n + 1];
    for(int i = 0; i<n + 1; i++){
        p[0][i] = 0;
        p[i][0] = 0;
    }

    for(int i = 1; i<n + 1; i++){
        for(int j = 1; j<n + 1; j++){
            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    for(int i = n; i>=1; i--){
        if(n % i != 0) continue;
        flag = 0;

        for(int j = 0; j<n; j+=i){
            for(int k = 0; k<n; k+=i){
                pref = p[j + i][k + i] - p[j + i][k] - p[j][k + i] + p[j][k];
                if(pref != 0 && pref != i*i){
                    flag = 1;
                    break;
                }
            }

            if (flag) break;
        }

        if(flag) continue;
        else{
            cout << i;
            return 0;

        }
    }

}