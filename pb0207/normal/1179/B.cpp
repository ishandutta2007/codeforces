#include<cstdio>
#include<cstring>
#include<algorithm>

int n, m;

int main() 
{    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n/2;i++) 
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d %d\n",i,j);
            printf("%d %d\n",n-i+1,m-j+1);
        }
    }
    if(n&1) 
    {
        int x=n/2+1;
        for(int i=1,l=1,r=m;i<=m;i++) 
     	{
            printf("%d %d\n",x,i&1?l++:r--);
        }
    }
}