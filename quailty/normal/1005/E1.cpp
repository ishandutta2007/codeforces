#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int a[MAXN],b[MAXN];
struct BIT
{
    int c[MAXN<<1],n;
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            c[i]=0;
    }
    void add(int p)
    {
        for(int i=p;i<=n;i+=i&-i)
            c[i]++;
    }
    int sum(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)
            res+=c[i];
        return res;
    }
}bit;
ll solve(int n,int m)
{
    for(int i=1;i<=n;i++)
        b[i]=(a[i]<=m ? 1 : -1);
    for(int i=1;i<=n;i++)
        b[i]+=b[i-1];
    bit.init(2*n+1);
    bit.add(n+1);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res+=bit.sum(b[i]+n+1);
        bit.add(b[i]+n+1);
    }
    return res;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%lld\n",solve(n,m)-solve(n,m-1));
    return 0;
}