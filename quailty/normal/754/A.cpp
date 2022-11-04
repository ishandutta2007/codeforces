#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]+=a[i-1];
    if(a[n]!=0)printf("YES\n1\n1 %d\n",n);
    else
    {
        int t=0;
        while(t<=n && a[t]==0)t++;
        if(t>n)printf("NO\n");
        else printf("YES\n2\n1 %d\n%d %d\n",t,t+1,n);
    }
    return 0;
}