#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=100005;
int x[MAXN],v[MAXN],t[MAXN];
int lef[1000005],rig[1000005];
bool check(int n,db m,int s)
{
    memset(lef,0,sizeof(lef));
    memset(rig,0,sizeof(rig));
    for(int i=1;i<=n;i++)
    {
        if(t[i]==1)
        {
            if(m>1.0*x[i]/v[i])lef[0]++;
            else lef[x[i]]++,lef[max(1LL*x[i],min(1000001LL,(long long)floor((m*(v[i]+s)-x[i])*(s-v[i])/s+x[i]))+1)]--;
        }
        else
        {
            if(m>1.0*(1000000-x[i])/v[i])rig[0]++;
            else rig[min(x[i]+1LL,max(0LL,(long long)ceil(x[i]-(m*(v[i]+s)+x[i]-1000000)*(s-v[i])/s)))]++,rig[x[i]+1]--;
        }
    }
    for(int i=1;i<=1000000;i++)
        lef[i]+=lef[i-1],rig[i]+=rig[i-1];
    for(int i=0;i<=1000000;i++)
        if(lef[i] && rig[i])return 1;
    return 0;
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&v[i],&t[i]);
    db l=1e-8,r=1e6;
    for(int _=0;_<60;_++)
    {
        db m=(l+r)/2;
        if(check(n,m,s))r=m;
        else l=m;
    }
    printf("%.12f\n",(l+r)/2);
    return 0;
}