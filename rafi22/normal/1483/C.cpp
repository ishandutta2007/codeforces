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

int h[300007];
int a[300007];
int DP[300007];
int seg[1100007],lazy[1100007],pot=1;

void push(int v)
{
    seg[2*v]+=lazy[v];
    seg[2*v+1]+=lazy[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}
void add(int v,int a,int b,int l,int r,int x)
{
    if(a<=l&&b>=r)
    {
        seg[v]+=x;
        lazy[v]+=x;
        return ;
    }
    if(l>b||r<a) return ;
    push(v);
    add(2*v,a,b,l,(l+r)/2,x);
    add(2*v+1,a,b,(l+r)/2+1,r,x);
    seg[v]=max(seg[2*v],seg[2*v+1]);
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(l>b||r<a) return -inf;
    push(v);
    return max(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        int n;
        cin>>n;
        while(pot<n) pot*=2;
        for(int i=0;i<=2*pot;i++) seg[i]=-inf;
        for(int i=1;i<=n;i++) cin>>h[i];
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int>Q;
        add(1,1,1,1,pot,inf);
        Q.pb(0);
        for(int i=1;i<=n;i++)
        {
            int last=i;
            while(sz(Q)>0&&h[Q.back()]>h[i])
            {
                int x=Q.back();
                Q.pop_back();
                add(1,Q.back()+1,x,1,pot,-a[x]);
            }
            add(1,Q.back()+1,i,1,pot,a[i]);
            Q.pb(i);
            DP[i]=que(1,1,i,1,pot);
            add(1,i+1,i+1,1,pot,inf+DP[i]);
        }
        cout<<DP[n];
    }

    return 0;
}