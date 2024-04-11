#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll Base=17LL;
const ll Mod=998244353LL;
char str[MAXN];
ll pp[MAXN];
void prepare()
{
    pp[0]=1LL;
    for(int i=1;i<MAXN;i++)
        pp[i]=Base*pp[i-1]%Mod;
}
ll fp(ll a,ll k,ll p)
{
    ll res=1LL%p;
    while(k)
    {
        if(k&1)res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}
ll inv=fp(Base-1,Mod-2,Mod)%Mod;
struct node
{
    int l,r,m;
    ll v,lazy;
}s[MAXN<<2];
void push_up(int n)
{
    s[n].v=(s[n<<1].v*pp[s[n<<1|1].r-s[n<<1|1].l]%Mod+s[n<<1|1].v)%Mod;
}
void set_value(int n,ll v)
{
    s[n].v=v*(pp[s[n].r-s[n].l]+Mod-1)%Mod*inv%Mod;
}
void push_down(int n)
{
    if(!s[n].lazy)return;
    set_value(n<<1,s[n].lazy);
    set_value(n<<1|1,s[n].lazy);
    s[n<<1].lazy=s[n].lazy;
    s[n<<1|1].lazy=s[n].lazy;
    s[n].lazy=0LL;
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    s[n].lazy=0LL;
    if(r-l==1)
    {
        set_value(n,str[l]-'0'+1);
        return;
    }
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    push_up(n);
}
void update(int l,int r,int n,ll v)
{
    if(s[n].l==l && s[n].r==r)
    {
        set_value(n,v);
        s[n].lazy=v;
        return;
    }
    push_down(n);
    if(r<=s[n].m)update(l,r,n<<1,v);
    else if(l>=s[n].m)update(l,r,n<<1|1,v);
    else
    {
        update(l,s[n].m,n<<1,v);
        update(s[n].m,r,n<<1|1,v);
    }
    push_up(n);
}
ll query(int l,int r,int n)
{
    if(r<=l)return 0LL;
    if(s[n].l==l && s[n].r==r)return s[n].v;
    push_down(n);
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return (query(l,s[n].m,n<<1)*pp[r-s[n].m]%Mod+query(s[n].m,r,n<<1|1))%Mod;
}
int main()
{
    prepare();
    int n,m,k;
    cin>>n>>m>>k;
    cin>>str+1;
    build(1,n+1,1);
    for(int i=1;i<=m+k;i++)
    {
        int op,l,r,x;
        cin>>op>>l>>r>>x;
        if(op==1)update(l,r+1,1,x+1);
        else cout<<((query(l,r+1-x,1)==query(l+x,r+1,1))? "YES" : "NO")<<endl;
    }
    return 0;
}