#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[300007];
int L[300007];
pair<int,int> seg[1100007];
int lazy[1100007],pot=1;
int seg1[1100007];
vector<int>vec[300007];
int sum(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg1[v];
    if(r<a||l>b) return 0;
    return sum(2*v,a,b,l,(l+r)/2)+sum(2*v+1,a,b,(l+r)/2+1,r);
}
void ins(int v)
{
    v+=pot-1;
    seg1[v]++;
    while(v>1)
    {
        v/=2;
        seg1[v]=seg1[2*v]+seg1[2*v+1];
    }
}

void add(int v,int a,int b,int l,int r,int x)
{
    if(a<=l&&b>=r)
    {
        seg[v].st+=x;
        lazy[v]+=x;
        return ;
    }
    if(l>b||r<a) return ;
    seg[2*v].st+=lazy[v];
    seg[2*v+1].st+=lazy[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
    add(2*v,a,b,l,(l+r)/2,x);
    add(2*v+1,a,b,(l+r)/2+1,r,x);
    seg[v]=min(seg[2*v],seg[2*v+1]);
}

vector<pair<int,int>>Q[300007];
int ans[300007];
bool is[300007];
bool was[300007];

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
        int n,q;
        cin>>n>>q;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]=i-a[i];
        }
        for(int i=1;i<=n;i++) L[i]=-1;
        int s=0;
        for(int i=1;i<=n;i++) seg[i+pot-1].nd=i;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=0&&a[i]<=s)
            {
                add(1,i,i,1,pot,s-a[i]);
                s++;
                is[i]=1;
            }
            else add(1,i,i,1,pot,inf);
        }
        for(int i=1;i<=n;i++)
        {
            if(is[i]&&!was[i])
            {
                L[i]=i;
                add(1,i,i,1,pot,inf);
                add(1,i+1,n,1,pot,-1);
                while(seg[1].st<0)
                {
                    int p=seg[1].nd;
                    was[p]=1;
                    L[p]=i;
                    add(1,p+1,n,1,pot,-1);
                    add(1,p,p,1,pot,inf);
                }
            }
        }
       // for(int i=1;i<=n;i++) cout<<L[i]<<" ";
      //  cout<<endl;
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            Q[n-y].pb({x,i});
        }
        for(int i=1;i<=n;i++)
        {
            if(L[i]>0) ins(L[i]);
            for(auto x:Q[i]) ans[x.nd]=sum(1,x.st+1,n,1,pot);
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }

    return 0;
}