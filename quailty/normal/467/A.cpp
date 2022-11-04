#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,res=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        res+=(p+2<=q);
    }
    return 0*printf("%d",res);
}