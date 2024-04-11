#include <bits/stdc++.h>

//#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<bool>T;
vector<pair<int,int>>Q;
vector<pair<pair<int,int>,int>>U;
int a[100007];
int ans[100007];
int x[30]={4,7,44,47,74,77,444, 744, 474, 774, 447, 747, 477, 777,4444, 7444, 4744, 7744, 4474, 7474, 4774, 7774, 4447, 7447, 4747, 7747, 4477, 7477, 4777, 7777};
pair<int,int> seg[600007];
int lazy[600007],pot=1,h=1;
int seg1[300007];
void build(int p)
{
    while(p>1)
    {
        p>>=1;
        if(p<pot)
        {
            seg[p]=min(seg[p<<1],seg[p<<1|1]);
            seg[p].st+=lazy[p];
        }
    }
}
void push(int p)
{
    for (int s=h;s>0;--s)
    {
        int i=p>>s;
        if (lazy[i]!=0)
        {
            seg[i<<1].st+=lazy[i];
            lazy[i<<1]+=lazy[i];
            seg[i<<1|1].st+=lazy[i];
            lazy[i<<1|1]+=lazy[i];
            lazy[i]=0;
        }
    }
}
void ins(int l,int r,int value)
{
    l+=pot,r+=pot;
    int l0=l,r0=r;
    for (;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            seg[l].st+=value;
            lazy[l]+=value;
            l++;
        }
        if(r&1)
        {
            --r;
            seg[r].st+=value;
            lazy[r]+=value;
        }
    }
    build(l0);
    build(r0 - 1);
}
void insP(int l,int value)
{
    l+=pot;
    seg[l].st+=value;
    lazy[l]+=value;
    build(l);
}
pair<int,int> que(int l,int r)
{
    l+=pot,r+=pot;
    push(l);
    push(r-1);
    pair<int,int> res={inf,inf};
    for (; l<r; l>>=1,r>>=1)
    {
        if(l&1)res=min(res,seg[l++]);
        if(r&1)res=min(seg[--r],res);
    }
    return res;
}

inline void ins1(int x,int val) {while(x<=pot)  {  seg1[x]+=val;  x+=(x&-x);  } }

inline int que1(int x) {int res=0;  while(x>0)  {  res+=seg1[x];  x-=(x&-x);  } return res; }

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,l,r,d;
        cin>>n>>m;
        while(pot<n)
        {
            pot*=2;
            h++;
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        while(m--)
        {
            string s;
            cin>>s;
            if(s=="add")
            {
                T.pb(0);
                cin>>l>>r>>d;
                U.pb({{l,r},d});
            }
            else
            {
                T.pb(1);
                cin>>l>>r;
                Q.pb({l,r});
            }
        }
        for(int k=0;k<30;k++)
        {
            for(int i=1; i<=n; i++)
            {
                if(a[i]==x[k])
                {
                    ins1(i,1);
                    seg[i+pot-1]={0,i};
                }
                else if(a[i]<x[k]) seg[i+pot-1]={x[k]-a[i],i};
                else seg[i+pot-1]={inf,i};
            }
            for(int i=pot-1;i>0;i--) seg[i]=min(seg[2*i],seg[2*i+1]);
            int it1=0,it2=0;
            for(auto t:T)
            {
                if(!t)
                {
                    l=U[it1].st.st,r=U[it1].st.nd,d=U[it1].nd;
                    ins(l-1,r,-d);
                    vector<int>xd;
                    while(true)
                    {
                        pair<int,int>p=que(l-1,r);
                        if(p.st>0) break;
                        if(p.st==0)
                        {
                            ins1(p.nd,1);
                            insP(p.nd-1,inf);
                            xd.pb(p.nd);
                        }
                        else if(p.st==-d)
                        {
                            ins1(p.nd,-1);
                            insP(p.nd-1,inf);
                        }
                        else insP(p.nd-1,inf);
                    }
                    for(auto lol:xd) insP(lol-1,-inf);
                    it1++;
                }
                else
                {
                    l=Q[it2].st,r=Q[it2].nd;
                    ans[it2]+=que1(r)-que1(l-1);
                    it2++;
                }
            }
            for(int i=1;i<2*pot;i++)
            {
                lazy[i]=0;
                seg1[i]=0;
            }
        }
        for(int i=0;i<sz(Q);i++) cout<<ans[i]<<endl;
    }

    return 0;
}