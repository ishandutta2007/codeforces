#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
typedef long long ll;
const int MAXN=100005;
int l[MAXN],r[MAXN];
int cnt(int x,int p)
{
    return x/p+1;
}
db get(int x,int n,int p)
{
    ll tot=1LL*(r[(x+1)%n]-l[(x+1)%n]+1)*(r[x]-l[x]+1);
    ll now=1LL*(r[(x+1)%n]-l[(x+1)%n]+1-(cnt(r[(x+1)%n],p)-cnt(l[(x+1)%n]-1,p)))*(r[x]-l[x]+1-(cnt(r[x],p)-cnt(l[x]-1,p)));
    return (tot-now+0.0)/tot;
}
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++)
        scanf("%d%d",&l[i],&r[i]);
    db res=0;
    for(int i=0;i<n;i++)
        res+=get(i,n,p);
    printf("%.10f\n",res*2000.0);
    return 0;
}