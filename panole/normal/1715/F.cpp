#include<bits/stdc++.h>
using namespace std;

int n,m;
double ans,x,y;

int main()
{
    scanf("%d%d",&n,&m);
    printf("? %d\n",2*n+2);
    printf("0 -1\n0 %d\n",m);
    for (int i=1; i<n; i++) printf("%d 0\n%d %d\n",i,i,m);
    printf("%d 0\n%d -1\n",n,n);
    fflush(stdout);
    scanf("%lf",&ans);
    y=m-(2*m*ans+1)/2.0;
    printf("? %d\n",2*m+2);
    printf("-1 0\n%d 0\n",n);
    for (int i=1; i<m; i++) printf("0 %d\n%d %d\n",i,n,i);
    printf("0 %d\n-1 %d\n",m,m);
    fflush(stdout);
    scanf("%lf",&ans);
    x=n-(2*n*ans+1)/2.0;
    printf("! %.10lf %.10lf\n",x,y);
    fflush(stdout);
    return 0;
}