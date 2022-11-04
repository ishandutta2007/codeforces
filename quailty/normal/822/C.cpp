#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=(1LL<<60)-1;
int l[MAXN],r[MAXN],c[MAXN];
int idx[MAXN],idy[MAXN];
ll mi[MAXN];
inline void check_min(ll &x,ll y)
{
    if(x>y)x=y;
}
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&l[i],&r[i],&c[i]);
    for(int i=1;i<MAXN;i++)
        idx[i]=idy[i]=i,mi[i]=INF;
    sort(idx+1,idx+n+1,[](int a,int b){return l[a]<l[b];});
    sort(idy+1,idy+n+1,[](int a,int b){return r[a]<r[b];});
    ll res=INF;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n && r[idy[j]]<l[idx[i]])check_min(mi[r[idy[j]]-l[idy[j]]+1],c[idy[j]]),j++;
        if(r[idx[i]]-l[idx[i]]+1<x)check_min(res,c[idx[i]]+mi[x-(r[idx[i]]-l[idx[i]]+1)]);
    }
    return 0*printf("%lld\n",(res<INF ? res : -1));
}