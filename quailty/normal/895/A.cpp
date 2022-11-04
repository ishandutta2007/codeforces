#include<bits/stdc++.h>
using namespace std;
int a[365];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]+=a[i-1];
    int res=360;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            res=min(res,abs(2*(a[i]-a[j])-a[n]));
    printf("%d\n",res);
    return 0;
}