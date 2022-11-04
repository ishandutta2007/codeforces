#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    int A;
    scanf("%d",&A);
    int u=0,d=A-2;
    for(int i=2;i<=A-1;i++)
    {
        int t=A;
        while(t)
        {
            u+=t%i;
            t/=i;
        }
    }
    int g=gcd(u,d);
    printf("%d/%d",u/g,d/g);
    return 0;
}