#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char p[5][5];

bool check(){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<2;j++){
            if(p[i][j] == 'x' && p[i][j+1] == 'x' && p[i][j+2] == 'x'){
                return 1;
            }
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<4;j++){
            if(p[i][j] == 'x' && p[i+1][j] == 'x' && p[i+2][j] == 'x'){
                return 1;
            }
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            if(p[i][j] == 'x' && p[i+1][j+1] == 'x' && p[i+2][j+2] == 'x'){
                return 1;
            }
        }
    }
    for(int i = 2;i<4;i++){
        for(int j = 0;j<2;j++){
            if(p[i][j] == 'x' && p[i-1][j+1] == 'x' && p[i-2][j+2] == 'x'){
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    for(int i = 0;i<4;i++)
        scanf("%s",p[i]);
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(p[i][j] != '.') continue;
            p[i][j] = 'x';
            if(check()){
                printf("YES\n");
                return 0;
            }
            p[i][j] = '.';
        }
    }
    printf("NO\n");
}