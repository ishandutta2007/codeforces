#include <bits/stdc++.h>

using namespace std;
int nzd(int a,int b)
{
    int m = max(a,b);
    int n = min(a,b);
    int r=1;
    while(r!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
int nzs(int a,int b)
{
    int x=nzd(a,b);
    return a*b/x;
}
int main()
{
    int x,y,a,b;
    scanf("%i %i %i %i",&x,&y,&a,&b);
    int n=nzs(x,y);
    int a1=(a-1)/n;
    int b1=(b)/n;
    printf("%i\n",b1-a1);
    return 0;
}