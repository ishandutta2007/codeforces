#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<pair<int,int>>V[500007];
int a[500007];
int b[500007];
int c[500007];
int DP[500007];

const int pot=1<<19;
int seg[2*pot+7],lazy[2*pot+7];

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

struct S
{
    int in,out,best,sum;
};
S Merge(S l,S r)
{
    return {max(r.in,l.in+r.sum),max(l.out,r.out+l.sum),max({l.best,r.best,l.in+r.out}),l.sum+r.sum};
}
S seg1[2*pot+7];
S que1(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg1[v];
    if(r<a||l>b) return {-inf,-inf,-inf,0};
    return Merge(que1(2*v,a,b,l,(l+r)/2),que1(2*v+1,a,b,(l+r)/2+1,r));
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
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>c[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=n;i>0;i--) a[i]+=a[i+1];
        for(int i=1;i<=n;i++) c[i]+=c[i-1];
        for(int i=1;i<=q;i++)
        {
            int l,r,x;
            cin>>l>>r>>x;
            V[l].pb({r,x});
        }
        for(int i=1;i<=2*pot;i++) seg[i]=-inf;
        DP[n+1]=-inf;
        for(int i=n;i>0;i--)
        {
            add(1,i,i,1,pot,inf+max(a[i],DP[i+1]));
            add(1,i,n,1,pot,b[i]);
            DP[i]=-inf;
            for(auto x:V[i])
            {
                DP[i]=max(DP[i],que(1,i,x.st,1,pot)-x.nd);
            }
        }
        for(int i=1;i<=n;i++) seg1[i+pot-1]={c[i]+b[i],max(a[i],DP[i+1])+b[i],c[i]+b[i]+max(a[i],DP[i+1]),b[i]};
        for(int i=n+1;i<=pot;i++) seg1[i+pot-1]={-inf,-inf,-inf,0};
        for(int i=pot-1;i>0;i--) seg1[i]=Merge(seg1[2*i],seg1[2*i+1]);
        int ans=-inf;
        for(int i=1;i<=n;i++)
        {
            for(auto x:V[i])
            {
                S t=que1(1,i,x.st,1,pot);
                ans=max(ans,t.best-x.nd);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}