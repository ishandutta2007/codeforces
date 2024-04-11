#include<bits/stdc++.h>
#define N 200010
#define M 2000010
#define mod 1000000007
#define mp make_pair
#define PII pair<int,int>
using namespace std;
set<PII >sat;
set<PII >::iterator it;
long long f[N],l[N],r[N],q[N],xx,yy;
int n,m,i,j,a[N],s,ss[N],st[N],en[N],head[N],ne[N],an[N],x,y,dad[N];
int find(int x){return dad[x]==x?x:dad[x]=find(dad[x]);}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        cin>>l[i]>>r[i];
    for(i=1;i<=m;i++)
    {
        cin>>f[i];
        q[i]=f[i];
        dad[i]=i;
    }
    sort(f+1,f+m+1);
    for(i=1;i<=m;i++)
    {
        q[i]=lower_bound(f+1,f+m+1,q[i])-f;
        a[find(q[i])]=i;dad[dad[q[i]]]=dad[q[i]]+1;
    }
    for(i=1;i<n;i++)
    {
        xx=r[i+1]-l[i];yy=l[i+1]-r[i];
        st[i]=lower_bound(f+1,f+m+1,yy)-f;
        en[i]=upper_bound(f+1,f+m+1,xx)-f-1;
        ne[i]=head[st[i]];head[st[i]]=i;
    }
    for(i=1;i<=m+1;i++)
    {
        for(j=head[i];j;j=ne[j])
            sat.insert(mp(en[j],j));
        if(i>m)break;
        it=sat.begin();
        if(it==sat.end())continue;
        x=(*it).first;y=(*it).second;
        if(x<i)break;
        an[y]=a[i];sat.erase(it);
    }
    if(i<=m||sat.size()){puts("No");return 0;}
    puts("Yes");
    for(i=1;i<n;i++)printf("%d ",an[i]);
}