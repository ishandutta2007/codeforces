#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[15][15];
int check(int x,int y)
{
    int res=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            res+=(s[x+i][y+j]=='#');
    return res;
}
int main()
{
    for(int i=0;i<4;i++)
        scanf("%s",s[i]);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(check(i,j)!=2)
                return 0*printf("YES");
    return 0*printf("NO");
}