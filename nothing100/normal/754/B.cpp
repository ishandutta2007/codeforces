#include<bits/stdc++.h>
using namespace std;
char ma[6][6],fx[4][2];
int check(int x,int y){
    if ((x>0)&&(y>0)&&(x<5)&&(y<5)) return 1;
    return 0;
}
int main(){
    fx[0][1]=1;
    fx[1][0]=1;
    fx[2][0]=1;
    fx[2][1]=1;
    fx[3][0]=1;
    fx[3][1]=-1;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++) scanf("%c",&ma[i][j]);
        scanf("\n");
    }
    for (int i=1;i<=4;i++)
    for (int j=1;j<=4;j++)
    if (ma[i][j]=='.'){
        for (int k=0;k<4;k++){
            int l=-1,r=1;
            while (check(i+fx[k][0]*l,j+fx[k][1]*l)&&(ma[i+fx[k][0]*l][j+fx[k][1]*l]=='x')) l--;
            while (check(i+fx[k][0]*r,j+fx[k][1]*r)&&(ma[i+fx[k][0]*r][j+fx[k][1]*r]=='x')) r++;
            if (r-l-1>=3){
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
}