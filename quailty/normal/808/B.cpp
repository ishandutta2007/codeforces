#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=200005;
int a[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    db res=0,now=0;
    for(int i=1;i<k;i++)
        now+=1.0*a[i]/(n-k+1);
    for(int i=k;i<=n;i++)
    {
        now+=1.0*(a[i]-a[i-k])/(n-k+1);
        res+=now;
    }
    return 0*printf("%.12f",res);
}