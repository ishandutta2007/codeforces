#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    if(n==1)return 0*printf("YES\n%d",x);
    if(n==2)
    {
        if(x==0)printf("NO\n");
        else printf("YES\n%d %d\n",0,x);
        return 0;
    }
    printf("YES\n");
    int t=0,u=(1<<18)-4;
    if(~n&1)printf("%d %d %d ",(1<<19)-1,1<<18,(1<<18)-2),n-=3,t^=1;
    while(n>1)printf("%d %d ",u,u+1),u-=2,n-=2,t^=1;
    printf("%d\n",x^t);
    return 0;
}