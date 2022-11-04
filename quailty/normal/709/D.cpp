#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[2][2];
char res[1000005];
bool check(int x,int y)
{
    if(a[0][1]+a[1][0]!=x*y)return 0;
    for(int i=0;i<x;i++)res[i]='0';
    for(int i=x;i<x+y;i++)res[i]='1';
    for(int i=x,j=a[1][0];i<x+y;i++)
    {
        if(j>x)
        {
            swap(res[i-x],res[i]);
            j-=x;
        }
        else
        {
            swap(res[i-j],res[i]);
            break;
        }
    }
    res[x+y]=0;
    return 1;
}
int main()
{
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<45000;i++)
    {
        if(i*(i-1)/2!=a[0][0])continue;
        for(int j=0;j<45000;j++)
        {
            if(j*(j-1)/2==a[1][1] && i+j>0 && check(i,j))
                return 0*printf("%s",res);
        }
    }
    printf("Impossible");
    return 0;
}