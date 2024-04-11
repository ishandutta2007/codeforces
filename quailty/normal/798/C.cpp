#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
int main()
{
    int n;
    scanf("%d",&n);
    int now=0,res=0,g=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        g=gcd(g,a);
        if(a&1)now++;
        else res+=(now+1)/2+now%2,now=0;
    }
    res+=(now+1)/2+now%2;
    printf("YES\n%d\n",(g>1 ? 0 : res));
    return 0;
}