#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
int a[MAXN],lef[MAXN],rig[MAXN];
struct BIT
{
    int c[MAXN],n;
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            c[i]=0;
    }
    void add(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)
            c[i]+=v;
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)
            res+=c[i];
        return res;
    }
}bit;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    bit.init(n);
    map<int,int> mp;
    for(int i=1;i<=n;i++)
        lef[i]=rig[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(mp.count(a[i]))continue;
        lef[a[i]]=mp[a[i]]=1;
        rig[a[i]]=a[i]+bit.query(n+1-a[i]);
        bit.add(n+1-a[i],1);
    }
    for(int i=1;i<=n;i++)
        if(!mp.count(i))
            rig[i]=i+bit.query(n+1-i);
    for(int i=n,k=0;i>=1;i--)
    {
        if(lef[i])k++;
        else lef[i]=i,rig[i]=i+k;
    }
    bit.init(m);
    mp.clear();
    for(int i=m;i>=1;i--)
    {
        int r=(mp.count(a[i]) ? mp[a[i]]-1 : m);
        mp[a[i]]=i;
        bit.add(i,1),bit.add(r+1,-1);
        rig[a[i]]=max(rig[a[i]],bit.query(r));
    }
    for(int i=1;i<=n;i++)
        printf("%d %d\n",lef[i],rig[i]);
    return 0;
}