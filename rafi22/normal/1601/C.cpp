#include <bits/stdc++.h>

//#define int long long
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
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

const int N=1000007;

int a[N],b[N];
unordered_map<int,int>M;
int ile[2*N];
vector<int>V[2*N];

int BIT[2*N];
int mx;
int que(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=BIT[x];
	return s;
}
void ins(int x,int s) {
	for (;x<=mx;x+=x&-x) BIT[x]+=s;
}

int seg[2*(2<<21)+7],lzy[2*(2<<21)+7];
void push(int v)
{
    lzy[2*v]+=lzy[v];
    lzy[2*v+1]+=lzy[v];
    seg[2*v]+=lzy[v];
    seg[2*v+1]+=lzy[v];
    lzy[v]=0;
}
void ins(int v,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return ;
    if(a<=l&&b>=r)
    {
        seg[v]+=x;
        lzy[v]+=x;
        return ;
    }
    push(v);
    ins(2*v,a,b,l,(l+r)/2,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,x);
    seg[v]=max(seg[2*v],seg[2*v+1]);
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
        M.clear();
        int n,m;
        cin>>n>>m;
        M.reserve(n+m+2);
        vector<pair<int,int>>V1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            V1.pb({a[i],i});
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
            V1.pb({b[i],n+i});
        }
        sort(all(V1));
        int it=0;
        if(V1[0].nd>n) b[V1[0].nd-n]=++it;
        else a[V1[0].nd]=++it;
        for(int i=1;i<sz(V1);i++)
        {
            if(V1[i].st!=V1[i-1].st) it++;
            if(V1[i].nd>n) b[V1[i].nd-n]=it;
            else a[V1[i].nd]=it;
        }
        ll ans=0;
        mx=it;
        for(int i=1;i<=n;i++)
        {
            ans+=(ll)que(it)-(ll)que(a[i]);
            ins(a[i],1);
            V[a[i]].pb(i);
        }
        for(int i=0;i<=mx;i++) BIT[i]=0;
        for(int i=1;i<=m;i++) ile[b[i]]++;
        int pot=1;
        while(pot<n+1) pot*=2;
        for(int i=1;i<2*pot;i++) lzy[i]=0;
        for(int i=n+1;i>0;i--) seg[i+pot-1]=n+1-i;
        for(int i=n+2;i<=pot;i++) seg[i+pot-1]=-inf;
        for(int i=pot-1;i>0;i--) seg[i]=max(seg[2*i],seg[2*i+1]);
        int c=n;
        for(int i=1;i<=it;i++)
        {
            for(auto x:V[i])
            {
                c--;
                ins(1,1,x,1,pot,-1);
            }
            ans+=(ll)ile[i]*(ll)(c-seg[1]);
            for(auto x:V[i]) ins(1,1,x,1,pot,-1);
            ile[i]=0;
            V[i].clear();
        }
        cout<<ans<<endl;
    }

    return 0;
}