#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[605][605];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int h,w;
        scanf("%d%d",&h,&w);
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                scanf("%d",&a[i][j]);
        int res=0;
        for(int j=1;j<=w;j++)
            res+=abs(a[h/2][j]-a[h/2+1][j]);
        printf("%s\n",(res>8000 ? "YES" : "NO"));
    }
    return 0;
}