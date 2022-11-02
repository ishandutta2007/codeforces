#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, pow;
    cin >> n;

    int res[5];
    fill(res, res + 5, 0);
    int q[n];
    char qq[n];

    bool qb[n][10];
    bool op[10][2];
    for(int i=0; i<10; i++){
        op[i][0]=0;
        op[i][1]=1;
    }

    for(int i=0; i<n; i++){
        cin >> qq[i] >> q[i];

        for(int j=0; j<10; j++){
            qb[i][j]=q[i]%2;
            q[i]/=2;
        }

        if(qq[i]=='|'){
            for(int j=0; j<10; j++){
                op[j][0]=op[j][0] || qb[i][j];
                op[j][1]=op[j][1] || qb[i][j];
            }
        }

        else if(qq[i]=='&'){
            for(int j=0; j<10; j++){
                op[j][0]=op[j][0] && qb[i][j];
                op[j][1]=op[j][1] && qb[i][j];
            }
        }

        else if(qq[i]=='^'){
            for(int j=0; j<10; j++){
                op[j][0]=op[j][0] ^ qb[i][j];
                op[j][1]=op[j][1] ^ qb[i][j];
            }
        }

    }

    pow=1;

    for(int j=0; j<10; j++){
        if(op[j][0]==1 && op[j][1]==1){
            res[1]+=pow;
            res[2]+=pow;
        }

        else if(op[j][0]==0 && op[j][1]==0){

        }

        else if(op[j][0]==0 && op[j][1]==1){
            res[2]+=pow;
        }

        else{
            res[0]+=pow;
            res[2]+=pow;
        }

        pow*=2;
    }

    cout << 3 << endl;
    cout << "^ " << res[0] << endl;
    cout << "| " << res[1] << endl;
    cout << "& " << res[2] << endl;

}