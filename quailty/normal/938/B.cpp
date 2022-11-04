#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=min(a[n]-1,1000000-a[1]);
    for(int i=1;i<=n;i++)
        res=min(res,max(a[i]-1,1000000-a[i+1]));
    printf("%d\n",res);
    return 0;
}