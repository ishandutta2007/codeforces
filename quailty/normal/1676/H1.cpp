#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
struct BIT
{
    int n,c[MAXN];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void add(int p)
    {
        for(int i=p;i>0;i-=i&-i)c[i]++;
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i<=n;i+=i&-i)res+=c[i];
        return res;
    }
}bit;
int solve()
{
    int n;
    scanf("%d",&n);
    bit.init(n);
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        res+=bit.query(a);
        bit.add(a);
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