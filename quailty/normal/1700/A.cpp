#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    return 0*printf("%lld\n",1LL*n*(n+1)/2*m+m*(m-1)/2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}