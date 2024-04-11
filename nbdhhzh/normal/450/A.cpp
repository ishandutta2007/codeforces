#include<cstdio>
using namespace std;
int n,m,i,x,max1,p;
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if ((x+m-1)/m>=max1)max1=(x+m-1)/m,p=i;
    }
    printf("%d",p);
}