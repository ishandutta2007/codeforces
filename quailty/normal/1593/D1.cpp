#include<bits/stdc++.h>
using namespace std;
const int MAXN=45;
int a[MAXN];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]!=a[j])res=__gcd(res,abs(a[i]-a[j]));
    printf("%d\n",(res ? res : -1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}