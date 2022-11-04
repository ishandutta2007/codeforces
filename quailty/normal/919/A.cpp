#include<bits/stdc++.h>
using namespace std;
typedef double db;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    db res=1e100;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        res=min(res,1.0*a/b*m);
    }
    printf("%.12f\n",res);
    return 0;
}