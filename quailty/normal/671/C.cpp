#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;

const int MAXN=200000;
const int MAXM=200000;

int a[MAXN+5],l[MAXM+5][2],r[MAXM+5][2];
void update(int x,int y,int n)
{
    if(l[x][0]>y)l[x][1]=l[x][0],l[x][0]=y;
    else if(l[x][1]>y)l[x][1]=y;
    if(r[x][0]<y)r[x][1]=r[x][0],r[x][0]=y;
    else if(r[x][1]<y)r[x][1]=y;
}

struct outline
{
    static ll area;
    ll x,y;
    outline(ll _x=0,ll _y=0):x(_x),y(_y){}
    bool operator < (const outline &t)const
    {
        return x<t.x;
    }
    bool contain(const outline &t)const
    {
        return x<=t.x && y>=t.y;
    }
    ll cover(ll MAXN)
    {
        return (MAXN-x+1)*y;
    }
    ll inter(const outline &t,ll MAXN)const
    {
        return (MAXN-max(x,t.x)+1)*min(y,t.y);
    }
};
ll outline::area=0;
set<outline>st;
void modify(outline t,ll n)
{
    auto itr=st.upper_bound(t);
    if(itr!=st.begin())itr--;
    if(itr==st.end())
    {
        st.insert(t);
        outline::area+=t.cover(n);
        return;
    }
    if(itr->contain(t))return;
    outline::area+=t.cover(n);
    if(itr->x <=t.x)
    {
        outline::area-=t.inter(*itr,n);
        itr++;
    }
    while(itr!=st.end())
    {
        outline::area-=t.inter(*itr,n);
        if(itr!=st.begin())
        {
            auto tmp=itr;
            outline::area+=itr->inter(*--tmp,n);
        }
        if(!t.contain(*itr))break;
        else itr++;
    }
    itr=st.lower_bound(t);
    while(itr!=st.end() && t.contain(*itr))
        st.erase(itr++);
    st.insert(t);
}

ll cnt[MAXM+5];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=MAXM;i++)
    {
        l[i][0]=l[i][1]=n+1;
        r[i][0]=r[i][1]=0;
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
        for(int j=1;j*j<=a[i];j++)
            if(a[i]%j==0)
            {
                update(j,i,n);
                if(j!=a[i]/j)update(a[i]/j,i,n);
            }
    }
    for(int i=2;i<=n;i++)
        modify(outline(i,i-1),n);
    cnt[mx+1]=outline::area;
    for(int i=mx;i>=1;i--)
    {
        if(r[i][1]>1)modify(outline(1,r[i][1]-1),n);
        if(r[i][1]>0)modify(outline(l[i][0]+1,r[i][0]-1),n);
        if(l[i][1]<n)modify(outline(l[i][1]+1,n),n);
        cnt[i]=outline::area;
    }
    ll res=0;
    for(int i=mx;i>=1;i--)
        res+=i*(cnt[i]-cnt[i+1]);
    printf("%I64d",res);
    return 0;
}