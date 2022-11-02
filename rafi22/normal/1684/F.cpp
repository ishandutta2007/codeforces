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

const bool multi=1;

const int N=200007;

int a[N];
vector<int>P[N];
int X[N];
int Y[N];

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
        vector<pair<int,int>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            V.pb({a[i],i});
        }
        sort(all(V));
        int it=1;
        a[V[0].nd]=it;
        for(int i=1;i<n;i++)
        {
            if(V[i].st!=V[i-1].st) it++;
            a[V[i].nd]=it;
        }
        for(int i=1;i<=n;i++) P[i].pb(-inf);
        for(int i=1;i<=n;i++) P[a[i]].pb(i);
        for(int i=1;i<=n;i++) P[i].pb(inf);
        while(m--)
        {
            int l,r;
            cin>>l>>r;
            X[l]=max(X[l],r);
        }
        int mx=0;
        int L=inf,R=-inf;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,X[i]);
            if(mx>=i)
            {
                int l=lower_bound(all(P[a[i]]),i)-P[a[i]].begin();
                int j=--upper_bound(all(P[a[i]]),mx)-P[a[i]].begin();
                if(j>l)
                {
                    ok=0;
                    if(j>l+1)
                    {
                        L=min(L,P[a[i]][l+1]);
                        R=max(R,P[a[i]][j-1]);
                    }
                    Y[1]=max(Y[1],P[a[i]][l]);
                    Y[P[a[i]][l]+1]=max(Y[P[a[i]][l]+1],P[a[i]][j]);
                    Y[P[a[i]][j]+1]=inf;
                }
            }
        }
        mx=0;
        int ans=inf;
        for(int i=1;i<=n;i++)
        {
            mx=max(Y[i],mx);
            if(mx!=inf) ans=min(ans,max(mx,R)-min(i,L)+1);
        }
        if(ok) ans=0;
        cout<<ans<<endl;
        for(int i=1;i<=n+3;i++)
        {
            P[i].clear();
            X[i]=0;
            Y[i]=0;
        }
    }

    return 0;
}