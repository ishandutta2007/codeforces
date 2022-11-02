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

int DP[200007];
int seg[800007][2],lazy[800007][2],pot=1;

void push(int v,int t)
{
    seg[2*v][t]+=lazy[v][t];
    seg[2*v+1][t]+=lazy[v][t];
    lazy[2*v][t]+=lazy[v][t];
    lazy[2*v+1][t]+=lazy[v][t];
    lazy[v][t]=0;
}
void ins(int v,int t,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return;
    if(a<=l&&b>=r)
    {
        seg[v][t]+=x;
        lazy[v][t]+=x;
        return ;
    }
    push(v,t);
    ins(2*v,t,a,b,l,(l+r)/2,x);
    ins(2*v+1,t,a,b,(l+r)/2+1,r,x);
    seg[v][t]=max(seg[2*v][t],seg[2*v+1][t]);
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
        int n,l,r,t;
        cin>>n;
        while(pot<n) pot*=2;
        vector<pair<int,pair<int,int>>>Q;
        set<pair<int,int>>S;
        for(int i=1;i<=n;i++)
        {
            cin>>l>>r>>t;
            Q.pb({r,{l,--t}});
        }
        sort(Q.begin(),Q.end());
        int i=2;
        S.insert({-inf,1});
        for(auto x:Q)
        {
            pair<int,int>p=*--S.lower_bound({x.nd.st,0});
            ins(1,x.nd.nd,1,p.nd,1,pot,1);
            DP[i]=max(seg[1][0],seg[1][1]);
            ins(1,0,i,i,1,pot,DP[i]);
            ins(1,1,i,i,1,pot,DP[i]);
            S.insert({x.st,i});
            i++;
        }
        cout<<DP[n+1];
    }

    return 0;
}