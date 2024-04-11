
 #include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int t[15][15];
int main()
{
    int dan[4]={0};
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d",&t[i][j]);
    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
            if(t[i][j])dan[i]=1,dan[(i+3-j)%4]=1;
//    for(int i=0;i<4;i++)
//        printf("%d ",dan[i]);
//    printf("\n");
    for(int i=0;i<4;i++)
        if(dan[i] && t[i][3])
            return 0*printf("YES");
    return 0*printf("NO");
}