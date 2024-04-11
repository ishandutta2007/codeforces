#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char sol[1000][10];
char red[10];
int n;
bool sl = false;

int main() {
    scanf("%d",&n);
    sl = false;
    for(int i = 0;i<n;i++){
        scanf("%s",red);
        for(int j = 0;j<5;j++)sol[i][j] = red[j];
        if(red[0] == red[1] && red[1] == 'O' && !sl){
            sol[i][0] = '+';sol[i][1] = '+';sl=true;
        }
        if(red[3] == red[4] && red[3] == 'O' && !sl){
            sol[i][3] = '+';sol[i][4] = '+';sl=true;
        }
    }
    if(sl) printf("YES\n");
    else {printf("NO\n");return 0;}
    for(int i = 0;i<n;i++){
        for(int j = 0;j<5;j++){
            printf("%c",sol[i][j]);
        }
        printf("\n");
    }
}