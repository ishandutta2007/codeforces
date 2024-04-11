#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char matrix[400][400];
char tmp[6][400][400];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%s", matrix[i]);
        for (int z=0;z<6;z++){
            for (int i=0;i<400;i++){
                for (int j=0;j<400;j++) tmp[z][i][j]=0;
            }
        }
        int c=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) {
                if (matrix[i][j]!='.') c++;
            }
        }
        //printf("%d\n", c);
        int ansnum=-100, tmp1=0;
        for (int z=0;z<3;z++){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    if (matrix[i][j]=='.'){
                        tmp[z][i][j]='.';
                        continue;
                    }
                    if ((i+j)%3==z){
                        if (matrix[i][j]=='O'){
                            tmp[z][i][j]='O';
                            continue;
                        }
                        else{
                            //printf("%d %d\n", i, j);
                            tmp1++;
                            tmp[z][i][j]='O';
                            continue;
                        }
                    }
                    else{
                        if (matrix[i][j]=='X'){
                            tmp[z][i][j]='X';
                            continue;
                        }
                        else{
                            //printf("%d %d\n", i, j);
                            tmp1++;
                            tmp[z][i][j]='X';
                            continue;
                        }
                    }
                }
            }
            if (tmp1<=(c/3)){
                ansnum=z;
                break;
            }
            tmp1=0;
        }
        //printf("%d %d\n", ansnum, tmp1);
        for (int z=3;z<6;z++){
            if (ansnum!=-100) break;
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    if (matrix[i][j]=='.'){
                        tmp[z][i][j]='.';
                        continue;
                    }
                    if ((i+j)%3==(z%3)){
                        if (matrix[i][j]=='X'){
                            tmp[z][i][j]='X';
                            continue;
                        }
                        else{
                            tmp1++;
                            tmp[z][i][j]='X';
                            continue;
                        }
                    }
                    else{
                        if (matrix[i][j]=='O'){
                            tmp[z][i][j]='O';
                            continue;
                        }
                        else{
                            tmp1++;
                            tmp[z][i][j]='O';
                            continue;
                        }
                    }
                }
            }
            if (tmp1<=(c/3)){
                ansnum=z;
                break;
            }
            tmp1=0;
        }
        //printf("%d %d\n", ansnum, tmp1);
        //if (ansnum==-100) continue;
        for (int i=0;i<n;i++){
            printf("%s\n", tmp[ansnum][i]);
        }
    }
    return 0;
}