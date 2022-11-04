#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[55][55];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    bool isok=1;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)if(a[x][y]>1)
        {
            bool flag=0;
            for(int s=1;s<=n;s++)
                for(int t=1;t<=n;t++)
                    flag|=(a[x][y]==a[x][s]+a[t][y]);
            isok&=flag;
        }
    printf("%s\n",(isok ? "Yes" : "No"));
    return 0;
}