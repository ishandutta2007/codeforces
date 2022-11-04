#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int b[2005];
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int res=0;
    for(int i=1;i<=n;i++)
        if(b[i]<=b[i-1])
        {
            int t=(b[i-1]-b[i])/d+1;
            res+=t;
            b[i]+=t*d;
        }
    printf("%d\n",res);
    return 0;
}