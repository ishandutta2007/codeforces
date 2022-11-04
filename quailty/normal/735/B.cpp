#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=100005;
ll a[MAXN];
int main()
{
    int n,n1,n2;
    scanf("%d%d%d",&n,&n1,&n2);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    db res=1.0*(a[n]-a[n-n1])/n1+1.0*(a[n-n1]-a[n-n1-n2])/n2;
    res=max(res,1.0*(a[n]-a[n-n2])/n2+1.0*(a[n-n2]-a[n-n1-n2])/n1);
    return 0*printf("%.8f",res);
}