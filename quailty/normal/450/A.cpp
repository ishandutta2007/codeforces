#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,res=0,loc=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(res<=(a+m-1)/m)
        {
            res=(a+m-1)/m;
            loc=i;
        }
    }
    return 0*printf("%d",loc);
}