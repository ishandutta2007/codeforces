#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=200007,pot=1<<18;

int x[N],y[N];
int ord[N];
int seg[2*pot+7];

void ins(int v,int x)
{
    v+=pot-1;
    seg[v]=x;
    while(v>1)
    {
        v/=2;
        seg[v]=max(seg[2*v],seg[2*v+1]);
    }
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b) return -inf;
    return max(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,v;
    cin>>n>>v;
    for(int i=1;i<=2*pot;i++) seg[i]=-inf;
    for(int i=1;i<=n;i++) cin>>y[i];
    for(int i=1;i<=n;i++) cin>>x[i];
    vector<pair<ll,int>>V;
    vector<pair<pair<ll,int>,int>>V1;
    V.pb({0,0});
    V1.pb({{0,0},0});
    for(int i=1;i<=n;i++)
    {
        V.pb({(ll)x[i]+(ll)v*(ll)y[i],i});
        V1.pb({{(ll)x[i]-(ll)v*(ll)y[i],-y[i]},i});
    }
    sort(all(V));
    sort(all(V1));
    for(int i=0;i<sz(V1);i++) ord[V1[i].nd]=sz(V1)-i;
    int ans=0;
    for(auto x:V)
    {
        //cout<<x.nd<<" "<<ord[x.nd]<<endl;
        int d=que(1,1,ord[x.nd],1,pot)+1;
        if(x.nd==0) d=0;
        ans=max(ans,d);
        ins(ord[x.nd],d);
    }
    cout<<ans;

    return 0;
}