#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool is_prime(int x)
{
    if(x==1)return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++)
        if(is_prime(i))for(int j=(i-1)/2;j>0;j--)
        {
            int p=j,q=i-1-j;
            if(is_prime(p) || is_prime(q))
            {
                k-=(p<q && is_prime(p) && is_prime(q));
                break;
            }
        }
    return 0*printf("%s",(k<=0 ? "YES" : "NO"));
}