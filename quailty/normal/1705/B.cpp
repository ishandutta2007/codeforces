#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ok=0,cnt=0;
    long long res=0;
    for(int i=1;i+1<=n;i++)
    {
        if(a[i])ok=1;
        else cnt+=ok;
        res+=a[i];
    }
    return 0*printf("%lld\n",res+cnt);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}