#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int cnt[26];
char str[MAXN],ans[MAXN];
struct node
{
    int l,r,m,v,lazy;
}s[26][MAXN<<2];
void push_up(int n,int id)
{
    s[id][n].v=s[id][n<<1].v+s[id][n<<1|1].v;
}
void push_down(int n,int id)
{
    if(s[id][n].lazy<0)return;
    s[id][n<<1].v=(s[id][n<<1].r-s[id][n<<1].l)*s[id][n].lazy;
    s[id][n<<1].lazy=s[id][n].lazy;
    s[id][n<<1|1].v=(s[id][n<<1|1].r-s[id][n<<1|1].l)*s[id][n].lazy;
    s[id][n<<1|1].lazy=s[id][n].lazy;
    s[id][n].lazy=-1;
}
void build(int l,int r,int n,int id)
{
    int m=(l+r)>>1;
    s[id][n].l=l;
    s[id][n].r=r;
    s[id][n].m=m;
    s[id][n].lazy=-1;
    if(r-l==1)
    {
        s[id][n].v=(str[l-1]=='a'+id);
        return;
    }
    build(l,m,n<<1,id);
    build(m,r,n<<1|1,id);
    push_up(n,id);
}
void update(int l,int r,int n,int op,int id)
{
    if(s[id][n].l==l && s[id][n].r==r)
    {
        s[id][n].v=(s[id][n].r-s[id][n].l)*op;
        s[id][n].lazy=op;
        return;
    }
    push_down(n,id);
    if(r<=s[id][n].m)update(l,r,n<<1,op,id);
    else if(l>=s[id][n].m)update(l,r,n<<1|1,op,id);
    else
    {
        update(l,s[id][n].m,n<<1,op,id);
        update(s[id][n].m,r,n<<1|1,op,id);
    }
    push_up(n,id);
}
int query(int l,int r,int n,int id)
{
    if(s[id][n].l==l && s[id][n].r==r)
        return s[id][n].v;
    push_down(n,id);
    if(r<=s[id][n].m)
        return query(l,r,n<<1,id);
    if(l>=s[id][n].m)
        return query(l,r,n<<1|1,id);
    return query(l,s[id][n].m,n<<1,id)
            +query(s[id][n].m,r,n<<1|1,id);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    scanf("%s",str);
    for(int i=0;i<26;i++)build(1,n+1,1,i);
    int l,r,k;
    while(q--)
    {
        scanf("%d%d%d",&l,&r,&k);
        for(int i=0;i<26;i++)
        {
            cnt[i]=query(l,r+1,1,i);
            update(l,r+1,1,0,i);
        }
        if(k==1)
        {
            int loc=l;
            for(int i=0;i<26;i++)
            {
                if(cnt[i]>0)update(loc,loc+cnt[i],1,1,i);
                loc+=cnt[i];
            }
        }
        else
        {
            int loc=l;
            for(int i=25;i>=0;i--)
            {
                if(cnt[i]>0)update(loc,loc+cnt[i],1,1,i);
                loc+=cnt[i];
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            if(query(i,i+1,1,j))
            {
                ans[i-1]='a'+j;
                break;
            }
    printf("%s\n",ans);
    return 0;
}