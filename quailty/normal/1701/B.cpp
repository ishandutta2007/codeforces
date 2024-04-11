#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n;
    scanf("%d",&n);
    printf("2\n");
    for(int i=1;i<=n;i+=2)
        for(int j=i;j<=n;j*=2)
            printf("%d ",j);
    return 0*printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}