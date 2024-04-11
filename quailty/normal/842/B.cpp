#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int R,d;
    scanf("%d%d",&R,&d);
    int n,res=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,r;
        scanf("%d%d%d",&x,&y,&r);
        int isok=1;
        isok&=(x*x+y*y>=(R-d+r)*(R-d+r));
        isok&=(r<=R && (x*x+y*y<=(R-r)*(R-r)));
        res+=isok;
    }
    return 0*printf("%d\n",res);
}