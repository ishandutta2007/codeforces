#include<bits/stdc++.h>
using namespace std;

int ptr,optr;
char buff[5000000],obuff[1000000];
inline int Read()
{
    char ch;
    while((ch=buff[ptr++])<'0' || ch>'9');
    int res=ch-'0';
    while((ch=buff[ptr++])>='0' && ch<='9')
        res=res*10+ch-'0';
    return res;
}
char stk[15];
inline void Print(int x)
{
    int tot=0;
    if(x==0)stk[tot++]='0';
    while(x)
    {
        stk[tot++]=x%10+'0';
        x/=10;
    }
    while(tot--)
        obuff[optr++]=stk[tot];
}

const int MAXN=200005;
const int MAXC=105;

int ls[MAXN*17],rs[MAXN*17];

int tot;
queue<int> bin;

inline int newnode(int ln=0)
{
    int n;
    if(bin.empty())n=++tot;
    else n=bin.front(),bin.pop();
    ls[n]=ls[ln];
    rs[n]=rs[ln];
    return n;
}

inline void delnode(int n)
{
    bin.push(n);
}

int merge(int u,int v)
{
    if(!u)return v;
    if(!v)return u;
    ls[u]=merge(ls[u],ls[v]);
    rs[u]=merge(rs[u],rs[v]);
    delnode(v);
    return u;
}

int ql,qr;
int split(int &u,int l,int r)
{
    if(!u)return 0;
    if(ql<=l && qr>=r)return r=u,u=0,r;
    int v=newnode(),m=(l+r)/2;
    if(ql<=m)ls[v]=split(ls[u],l,m);
    if(qr>m)rs[v]=split(rs[u],m+1,r);
    return v;
}

int p;
inline void add(int l,int r,int n)
{
    while(l<r)
    {
        int m=(l+r)/2;
        if(p<=m)
        {
            if(!ls[n])ls[n]=newnode();
            n=ls[n],r=m;
        }
        else
        {
            if(!rs[n])rs[n]=newnode();
            n=rs[n],l=m+1;
        }
    }
}

int res[MAXN];
void dfs(int l,int r,int n,int id)
{
    if(!n)return;
    if(l==r)
    {
        res[l]=id;
        return;
    }
    int m=(l+r)/2;
    dfs(l,m,ls[n],id);
    dfs(m+1,r,rs[n],id);
}

int rt[MAXC];

int main()
{
    fread(buff,1,sizeof(buff),stdin);
    int n=Read();
    for(int i=1;i<=n;i++)
    {
        int a=Read();
        if(!rt[a])rt[a]=newnode();
        p=i,add(1,n,rt[a]);
    }
    int q=Read();
    while(q--)
    {
        int l=Read(),r=Read(),x=Read(),y=Read();
        if(x!=y)ql=l,qr=r,rt[y]=merge(rt[y],split(rt[x],1,n));
    }
    for(int i=0;i<MAXC;i++)
        dfs(1,n,rt[i],i);
    for(int i=1;i<=n;i++)
        Print(res[i]),obuff[optr++]=" \n"[i==n];
    fwrite(obuff,1,optr,stdout);
    return 0;
}