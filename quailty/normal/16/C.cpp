#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    int a,b,x,y;
    scanf("%d%d%d%d",&a,&b,&x,&y);
    int g=gcd(x,y);
    x/=g,y/=g;
    int t=min(a/x,b/y);
    return 0*printf("%d %d",t*x,t*y);
}