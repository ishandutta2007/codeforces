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

int a[300007];
int b[300007];

int seg[4*1000007];
int lazy[4*1000007],pot=(1<<20);

void ins(int v,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return ;
    if(a<=l&&b>=r)
    {
        seg[v]+=x;
        lazy[v]+=x;
        return ;
    }
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    seg[2*v]+=lazy[v];
    seg[2*v+1]+=lazy[v];
    lazy[v]=0;
    ins(2*v,a,b,l,(l+r)/2,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,x);
    seg[v]=min(seg[2*v],seg[2*v+1]);
}

int que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return inf;
    if(l>=a&&b>=r) return seg[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    seg[2*v]+=lazy[v];
    seg[2*v+1]+=lazy[v];
    lazy[v]=0;
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}


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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ins(1,1,a[i],1,pot,-1);
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            ins(1,1,b[i],1,pot,1);
        }
        int q;
        cin>>q;
        while(q--)
        {
            int t,i,x;
            cin>>t>>i>>x;
            if(t==1)
            {
                ins(1,1,a[i],1,pot,1);
                a[i]=x;
                ins(1,1,a[i],1,pot,-1);
            }
            else
            {
                ins(1,1,b[i],1,pot,-1);
                b[i]=x;
                ins(1,1,b[i],1,pot,1);
            }
            int l=1,r=1000000,sr,ans=-1;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(que(1,sr,1000000,1,pot)<0)
                {
                    ans=sr;
                    l=sr+1;
                }
                else r=sr-1;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}