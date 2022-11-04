#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return 0;
    return 1;
}
int np[1000005];
void build()
{
    np[0]=1;
    np[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(!np[i])
        {
            if(i<=1000)
            {
                for(int j=i*i;j<=1000000;j+=i)np[j]=1;
            }
        }
    }
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    if(is_prime(n))
    {
        printf("1\n");
        printf("%d\n",n);
    }
    else if(is_prime(n-2))
    {
        printf("2\n");
        printf("%d %d\n",2,n-2);
    }
    else
    {
        int a=n;
        for(int i=n;i>0;i--)
        {
            if(is_prime(i))
            {
                a=i;
                break;
            }
        }
        n-=a;
        int b=n;
        for(int i=n;i>0;i--)
        {
            if((!np[i]) && (!np[n-i]))
            {
                b=i;
                break;
            }
        }
        n-=b;
        printf("3\n");
        printf("%d %d %d\n",a,b,n);
    }
    return 0;
}