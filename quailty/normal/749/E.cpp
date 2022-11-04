#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const int MAXN=100005;
int p[MAXN];
ll c[MAXN];
void update(int p,ll v,int n)
{
    for(int i=p;i<=n;i+=i&-i)c[i]+=v;
}
ll query(int p)
{
    ll res=0;
    for(int i=p;i>0;i-=i&-i)res+=c[i];
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    db res=0;
    for(int i=1;i<=n;i++)
        res+=1.0*i*(i-1)/2*(n-i+1)/n/(n+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    memset(c,0,sizeof(c));
    for(int i=n;i>=1;i--)
    {
        res+=1.0*query(p[i]);
        update(p[i],1,n);
    }
    memset(c,0,sizeof(c));
    for(int i=n;i>=1;i--)
    {
        res-=2.0*query(p[i])*i/n/(n+1);
        update(p[i],n-i+1,n);
    }
    return 0*printf("%.12f",res);
}