#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=100005;
const db eps=1e-12;
db p[2][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",&p[0][i]);
    for(int i=1;i<=n;i++)
        scanf("%lf",&p[1][i]);
    for(int _=0;_<2;_++)
        for(int i=1;i<=n;i++)
            p[_][i]+=p[_][i-1];
    for(int i=1;i<=n;i++)
    {
        db x=p[0][i],y=p[1][i];
        p[0][i]=((x+y)+sqrt((x+y)*(x+y)-4.0*x+eps))/2.0;
        p[1][i]=((x+y)-sqrt((x+y)*(x+y)-4.0*x+eps))/2.0;
    }
    for(int _=0;_<2;_++)
        for(int i=n;i>=1;i--)
            p[_][i]-=p[_][i-1];
    for(int _=0;_<2;_++,printf("\n"))
        for(int i=1;i<=n;i++)
            printf("%.8f ",p[_][i]);
    return 0;
}