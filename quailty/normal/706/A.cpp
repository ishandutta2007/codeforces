#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int n;
    double res=1e10;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        res=min(res,sqrt((x-a)*(x-a)+(y-b)*(y-b))/v);
    }
    return 0*printf("%.10f",res);
}