#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll c[15][MAXN];
int lowbit(int x)
{
    return x&(-x);
}
void update(int p,ll v,int n,int id)
{
    for(int i=p;i<=n;i+=lowbit(i))c[id][i]+=v;
}
ll query(int p,int id)
{
    ll res=0;
    for(int i=p;i>0;i-=lowbit(i))res+=c[id][i];
    return res;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        update(a,1,n,0);
        for(int i=1;i<=k;i++)
            update(a,query(a-1,i-1),n,i);
    }
    printf("%I64d\n",query(n,k));
    return 0;
}