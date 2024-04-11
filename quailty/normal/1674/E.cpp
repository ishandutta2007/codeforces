#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=INF;
    for(int i=2;i<=n;i++)
    {
        if(i<n)res=min(res,(a[i-1]+a[i+1]+1)/2);
        if(2*a[i-1]<a[i])res=min(res,(a[i]+1)/2);
        else if(2*a[i]<a[i-1])res=min(res,(a[i-1]+1)/2);
        else res=min(res,(a[i-1]+a[i]+2)/3);
    }
    nth_element(a+1,a+2,a+n+1);
    res=min(res,(a[1]+1)/2+(a[2]+1)/2);
    return 0*printf("%d\n",res);
}