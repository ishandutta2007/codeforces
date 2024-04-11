#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int a[4];
    for(int i=0;i<4;i++)
        scanf("%d",&a[i]);
    int sum=accumulate(a,a+4,0);
    return 0*printf("%d\n",(sum==0 ? 0 : sum==4 ? 2 : 1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}