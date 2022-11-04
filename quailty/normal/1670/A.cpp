#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int solve()
{
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),cnt+=(a[i]<0);
    for(int i=1;i<=n;i++)
        a[i]=(i<=cnt ? -1 : 1)*abs(a[i]);
    return 0*printf("%s\n",is_sorted(a+1,a+n+1) ? "YES" : "NO");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}