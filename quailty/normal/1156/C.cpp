#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int x[MAXN];
int main()
{
    int n,z;
    scanf("%d%d",&n,&z);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    int l=0,r=n/2;
    while(l<r)
    {
        int m=(l+r+1)/2;
        bool isok=1;
        for(int i=1,j=n-m+1;j<=n;i++,j++)
            isok&=(x[j]-x[i]>=z);
        if(isok)l=m;
        else r=m-1;
    }
    printf("%d\n",l);
    return 0;
}