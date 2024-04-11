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
    for(int i=n;i>=1;i-=2)
        if(a[i-1]>a[i])swap(a[i-1],a[i]);
    return 0*printf("%s\n",(is_sorted(a+1,a+n+1) ? "YES" : "NO"));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}