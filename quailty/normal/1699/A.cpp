#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    scanf("%d",&n);
    if(n&1)printf("-1\n");
    else printf("0 0 %d\n",n/2);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}