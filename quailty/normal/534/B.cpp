#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int v1,v2,t,d;
    scanf("%d%d%d%d",&v1,&v2,&t,&d);
    int ans=0;
    for(int i=1;i<=t;i++)
    {
        ans+=min(v1+(i-1)*d,v2+(t-i)*d);
    }
    printf("%d\n",ans);
    return 0;
}