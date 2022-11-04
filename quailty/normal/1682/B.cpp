#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int p[MAXN];
int solve()
{
    int n,res=(1<<30)-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        if(p[i]!=i)res&=p[i];
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