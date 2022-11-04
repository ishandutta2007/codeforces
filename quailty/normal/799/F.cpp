#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int l[MAXN],r[MAXN],cnt[MAXN];
vector<pair<int,int>> event[MAXN];
struct info
{
    int m,s;
    ll t;
    info(){}
    info(int _m,int _s,ll _t):m(_m),s(_s),t(_t){}
    info operator + (const info &rhs)const
    {
        if(m<rhs.m)return *this;
        if(m>rhs.m)return rhs;
        return info(m,s+rhs.s,t+rhs.t);
    }
};
struct node
{
    int l,r,m;
    info v;
    int lz;
}s[2][MAXN<<2];
void push_up(int n,int id)
{
    s[id][n].v=s[id][n<<1].v+s[id][n<<1|1].v;
}
void push_down(int n,int id)
{
    if(!s[id][n].lz)return;
    s[id][n<<1].v.m+=s[id][n].lz;
    s[id][n<<1].lz+=s[id][n].lz;
    s[id][n<<1|1].v.m+=s[id][n].lz;
    s[id][n<<1|1].lz+=s[id][n].lz;
    s[id][n].lz=0;
}
void build(int l,int r,int n,int id)
{
    s[id][n].l=l;
    s[id][n].r=r;
    s[id][n].m=(l+r)/2;
    s[id][n].lz=0;
    if(l==r)
    {
        s[id][n].v=info(0,(l&1)==id,((l&1)==id)*l);
        return;
    }
    build(l,s[id][n].m,n<<1,id);
    build(s[id][n].m+1,r,n<<1|1,id);
    push_up(n,id);
}
void update(int l,int r,int v,int n,int id)
{
    if(r<l)return;
    if(l==s[id][n].l && r==s[id][n].r)
    {
        s[id][n].v.m+=v;
        s[id][n].lz+=v;
        return;
    }
    push_down(n,id);
    if(r<=s[id][n].m)update(l,r,v,n<<1,id);
    else if(l>s[id][n].m)update(l,r,v,n<<1|1,id);
    else
    {
        update(l,s[id][n].m,v,n<<1,id);
        update(s[id][n].m+1,r,v,n<<1|1,id);
    }
    push_up(n,id);
}
info query(int l,int r,int n,int id)
{
    if(l==s[id][n].l && r==s[id][n].r)return s[id][n].v;
    push_down(n,id);
    if(r<=s[id][n].m)return query(l,r,n<<1,id);
    if(l>s[id][n].m)return query(l,r,n<<1|1,id);
    return query(l,s[id][n].m,n<<1,id)+query(s[id][n].m+1,r,n<<1|1,id);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        cnt[l[i]]++,cnt[r[i]+1]--;
        event[l[i]].push_back(make_pair(i,1));
        event[r[i]].push_back(make_pair(i,-1));
    }
    for(int i=1;i<=m;i++)
        cnt[i]+=cnt[i-1];
    cnt[m+1]=-1;
    ll res=0;
    for(int i=1,len=0;i<=m+1;i++)
    {
        if(cnt[i])
        {
            for(int j=1;j<=len;j++)
                res-=1LL*j*(len-j+1);
            len=0;
        }
        else len++;
    }
    for(int _=0;_<2;_++)
    {
        for(int j=0;j<2;j++)
            build(1,m,1,j);
        for(int i=1;i<=n;i++)
            update(l[i],r[i],1,1,_^1);
        for(int i=2-_;i<=m;i+=2)
        {
            for(int j=0;j<(int)event[i-1].size();j++)
            {
                int t=event[i-1][j].first;
                if(event[i-1][j].second==1)
                {
                    update(1,l[t]-1,1,1,0);
                    update(1,l[t]-1,1,1,1);
                }
                else
                {
                    if((l[t]&1)==(_^1))
                    {
                        update(1,l[t]-1,-1,1,0);
                        update(1,l[t]-1,-1,1,1);
                    }
                    else
                    {
                        update(1,l[t]-1,1,1,0);
                        update(1,l[t]-1,1,1,1);
                    }
                    update(l[t],r[t],-1,1,_^1);
                    update(l[t],r[t],1,1,_);
                }
            }
            info tmp=query(1,i,1,0)+query(1,i,1,1);
            if(tmp.m==0)res+=1LL*(i+1)*tmp.s-tmp.t;
        }
    }
    return 0*printf("%lld\n",res);
}