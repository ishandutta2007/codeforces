#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
const int MAXN=500005;
map<int,int>mp;
int a[MAXN],la[MAXN],id[MAXN],dp[MAXN],fp[MAXN];
pair<int,int>pre[MAXN];
struct node
{
    pair<int,int>v;
    int ls,rs;
}s[MAXN*25];
int rt[MAXN],tot;
void pushUp(int n)
{
    s[n].v=max(s[s[n].ls].v,s[s[n].rs].v);
}
void build(int l,int r,int &n)
{
    n=++tot;
    if(l==r)
    {
        s[n].v=make_pair(0,0);
        return;
    }
    int m=(l+r)/2;
    build(l,m,s[n].ls);
    build(m+1,r,s[n].rs);
    pushUp(n);
}
void update(int p,pair<int,int> v,int l,int r,int ln,int &n)
{
    s[n=++tot]=s[ln];
    if(l==r)
    {
        s[n].v=max(s[n].v,v);
        return;
    }
    int m=(l+r)/2;
    if(p<=m)update(p,v,l,m,s[ln].ls,s[n].ls);
    else update(p,v,m+1,r,s[ln].rs,s[n].rs);
    pushUp(n);
}
pair<int,int> query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return s[n].v;
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,s[n].ls);
    if(ql>m)return query(ql,qr,m+1,r,s[n].rs);
    return max(query(ql,m,l,m,s[n].ls),query(m+1,qr,m+1,r,s[n].rs));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        la[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++)id[i]=i;
    sort(id+1,id+n+1,[](int a,int b){return la[a]<la[b];});
    build(1,n,rt[0]);
    for(int ti=1;ti<=n;ti++)
    {
        int i=id[ti];
        update(i,make_pair(la[i],a[i]),1,n,rt[la[id[ti-1]]],rt[la[i]]);
    }
    for(int i=1;i<=n;i++)
    {
        if(la[i]>0 && la[i]<i-1)
        {
            pair<int,int> tmp=query(la[i]+1,i-1,1,n,rt[la[i]]);
            if(tmp.first>0 && dp[i]<fp[tmp.first-1]+4)
            {
                dp[i]=fp[tmp.first-1]+4;
                pre[i]=make_pair(tmp.first,0);
            }
        }
        int loc=i;
        for(int i=1;i<4;i++)
            loc=la[loc];
        if(loc>0 && dp[i]<fp[loc-1]+4)
        {
            dp[i]=fp[loc-1]+4;
            pre[i]=make_pair(loc,1);
        }
        fp[i]=max(fp[i-1],dp[i]);
    }
    stack<int>res;
    for(int i=n;i>=1;i--)
        if(fp[i]>fp[i-1])
        {
            if(pre[i].second)
            {
                for(int j=0;j<4;j++)
                    res.push(a[i]);
            }
            else
            {
                pair<int,int> tmp=query(la[i]+1,i-1,1,n,rt[la[i]]);
                res.push(a[i]);
                res.push(tmp.second);
                res.push(a[i]);
                res.push(tmp.second);
            }
            i=pre[i].first;
        }
    printf("%d\n",(int)res.size());
    while(!res.empty())
    {
        printf("%d ",res.top());
        res.pop();
    }
    return 0;
}