#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x[105];
int main()
{
    int n,c,res=0;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<n;i++)
        res=max(res,x[i]-x[i+1]-c);
    return 0*printf("%d",res);
}