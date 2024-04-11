#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,m,res=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(m>a)m-=a;
        else res+=a-m,m=0;
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