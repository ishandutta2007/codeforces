#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int x[MAXN];
int main()
{
    int n,a;
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    if(n==1)return 0*printf("0");
    sort(x+1,x+n+1);
    int res=min(abs(a-x[1]),abs(a-x[n-1]))+abs(x[1]-x[n-1]);
    res=min(res,min(abs(a-x[2]),abs(a-x[n]))+abs(x[2]-x[n]));
    return 0*printf("%d",res);
}