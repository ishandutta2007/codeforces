#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int x[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int d=-1;d<=1;d++)
    {
        int l=x[1]+d,isok=1;
        for(int i=2;i<=n;i++)
            isok&=(abs(x[i]-(l+i-1))<=1);
        if(isok)return 0*printf("YES\n");
    }
    return 0*printf("NO\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}