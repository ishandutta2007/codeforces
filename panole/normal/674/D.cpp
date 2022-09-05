#include<bits/stdc++.h>
using namespace std;
 
long long ans[100010],laz[100010],b[100010];
int a[100010],D[100010],n,q,ord,x,y;
multiset<long long> s[100010],ma,mi;
multiset<long long>::iterator it,itt;
vector<int> v[100010];
 
int read()
{
    int p=0; char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
    return p;
}
 
void add(int y)
{
    if (!s[y].size()) return;
    it=s[y].end(),it--;
    ma.insert((*it)+laz[y]);
    it=s[y].begin();
    mi.insert((*it)+laz[y]);
}
 
void dlt(int y)
{
    if (!s[y].size()) return;
    it=s[y].end(),it--;
    itt=ma.find((*it)+laz[y]);
    ma.erase(itt);
    it=s[y].begin();
    itt=mi.find((*it)+laz[y]);
    mi.erase(itt);
}
 
void ins(int x,int y)
{
    dlt(y),dlt(a[y]),dlt(a[a[y]]);
    ans[x]+=(b[y]/D[y])-laz[y];
    s[y].insert(ans[x]),it=s[a[y]].find(ans[y]);
    s[a[y]].erase(it),it=s[a[a[y]]].find(ans[a[y]]);
    s[a[a[y]]].erase(it);
    ans[y]+=(b[y]/D[y])*(D[y]-1)-(b[y]/(D[y]+1))*D[y];
    ans[y]+=(b[x]/D[x]),laz[y]+=b[y]/(D[y]+1)-b[y]/D[y];
    ans[a[y]]+=b[y]/(D[y]+1)-b[y]/D[y];
    s[a[a[y]]].insert(ans[a[y]]);
    s[a[y]].insert(ans[y]);
    add(a[a[y]]),add(a[y]),add(y),D[y]++;
}
 
void del(int x,int y)
{
    dlt(y),dlt(a[y]),dlt(a[a[y]]);
    it=s[y].find(ans[x]);
    s[y].erase(it);
    ans[x]+=laz[y]-(b[y]/D[y]),it=s[a[y]].find(ans[y]);
    s[a[y]].erase(it),it=s[a[a[y]]].find(ans[a[y]]);
    s[a[a[y]]].erase(it);
    ans[y]+=(b[y]/D[y])*(D[y]-1)-(b[y]/(D[y]-1))*(D[y]-2);
    ans[y]-=(b[x]/D[x]),laz[y]+=b[y]/(D[y]-1)-b[y]/D[y];
    ans[a[y]]+=b[y]/(D[y]-1)-b[y]/D[y];
    s[a[a[y]]].insert(ans[a[y]]);
    s[a[y]].insert(ans[y]);
    add(a[a[y]]),add(a[y]),add(y),D[y]--;
}
 
int main()
{
    n=read(),q=read(),ma.clear(),mi.clear();
    for (int i=1; i<=n; i++) scanf("%lld",&b[i]);
    for (int i=1; i<=n; i++) a[i]=read(); 
    for (int i=1; i<=n; i++) s[i].clear(),v[i].clear(),D[i]=2,laz[i]=0;
    for (int i=1; i<=n; i++) D[a[i]]++,v[a[i]].push_back(i),v[i].push_back(a[i]);
    for (int i=1; i<=n; i++) 
    {
        ans[i]=b[i]-(b[i]/D[i])*(D[i]-1);
        for (int j=0,siz=v[i].size(); j<siz; j++)
            x=v[i][j],ans[i]+=(b[x]/D[x]);
    }
    for (int i=1; i<=n; i++) s[a[i]].insert(ans[i]);
    for (int i=1; i<=n; i++) add(i);
    while (q--)
    {
        ord=read();
        if (ord==1)
        {
            x=read(),y=read();
            del(x,a[x]),a[x]=y,ins(x,y);
        } else
        if (ord==2)
        {
            x=read(),printf("%lld\n",laz[a[x]]+ans[x]);
        } else
        {
            it=mi.begin(),printf("%lld ",(*it));
            it=ma.end(),it--,printf("%lld\n",(*it));
        }
    }
    return 0;
}