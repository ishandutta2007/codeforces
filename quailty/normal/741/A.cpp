#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int f[MAXN];
int main()
{
    int n,res=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);
    for(int i=1;i<=n;i++)
    {
        int t=i,j=0;
        while(j<=n)
        {
            t=f[t],j++;
            if(t==i)
            {
                res=lcm(res,j/(j&1 ? 1 : 2));
                break;
            }
        }
        if(j>n)return 0*printf("-1");
    }
    return 0*printf("%d",res);
}