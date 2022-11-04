#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool vish[55],visv[55];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++)
    {
        int h,v;
        scanf("%d%d",&h,&v);
        if(!vish[h] && !visv[v])
        {
            printf("%d ",i);
            vish[h]=1;
            visv[v]=1;
        }
    }
    return 0;
}