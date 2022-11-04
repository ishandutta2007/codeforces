#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int c[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        c[i]=c[i-1]+(a<i);
        if(a<i)res+=c[max(0,a-1)];
    }
    return 0*printf("%lld\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}