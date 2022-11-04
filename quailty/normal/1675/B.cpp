#include<bits/stdc++.h>
using namespace std;
const int MAXN=35;
int a[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=n-1;i>=1;i--)
    {
        while(a[i]>0 && a[i]>=a[i+1])a[i]/=2,res++;
        if(a[i]==a[i+1])return 0*printf("-1\n");
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}