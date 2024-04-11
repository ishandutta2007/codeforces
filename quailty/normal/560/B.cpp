#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[3][2];
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    bool isok=0;
    for(int i=0;i<2;i++)
    {
        swap(a[0][0],a[0][1]);
        if(a[1][0]+a[2][0]<=a[0][0] && max(a[1][1],a[2][1])<=a[0][1])isok=1;
        if(a[1][0]+a[2][1]<=a[0][0] && max(a[1][1],a[2][0])<=a[0][1])isok=1;
        if(a[1][1]+a[2][0]<=a[0][0] && max(a[1][0],a[2][1])<=a[0][1])isok=1;
        if(a[1][1]+a[2][1]<=a[0][0] && max(a[1][0],a[2][0])<=a[0][1])isok=1;
    }
    printf("%s\n",(isok ? "YES" : "NO"));
    return 0;
}