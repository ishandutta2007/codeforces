#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int a[MAXN],l[MAXN],r[MAXN],id[MAXN],res[MAXN];
int pre[MAXN],nxt[MAXN];
pair<int,int> s[MAXN<<2];
void update(int ql,int qr,pair<int,int> v,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        s[n]=max(s[n],v);
        return;
    }
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,v,l,m,n<<1);
    else if(ql>m)update(ql,qr,v,m+1,r,n<<1|1);
    else
    {
        update(ql,m,v,l,m,n<<1);
        update(m+1,qr,v,m+1,r,n<<1|1);
    }
}
pair<int,int> query(int p,int t,int l,int r,int n)
{
    if(l==r)return s[n];
    int m=(l+r)/2;
    if(p<=m)return max(s[n],query(p,t,l,m,n<<1));
    return max(s[n],query(p,t,m+1,r,n<<1|1));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        if(!mp[a[i]])pre[i]=0;
        else pre[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    mp.clear();
    for(int i=n;i>=1;i--)
    {
        if(!mp[a[i]])nxt[i]=n+1;
        else nxt[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d",&l[i],&r[i]),id[i]=i;
    sort(id+1,id+q+1,[](int x,int y){return r[x]<r[y];});
    for(int ii=1,j=1;ii<=q;ii++)
    {
        int i=id[ii];
        while(j<=r[i])update(pre[j]+1,j,{nxt[j],a[j]},1,n,1),j++;
        pair<int,int> t=query(l[i],j,1,n,1);
        res[i]=(t.first>=j ? t.second : 0);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",res[i]);
    return 0;
}