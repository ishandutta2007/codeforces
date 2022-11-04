#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,res=0,m=0x3f3f3f3f;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,p;
        scanf("%d%d",&a,&p);
        m=min(m,p);
        res+=a*m;
    }
    return 0*printf("%d",res);
}