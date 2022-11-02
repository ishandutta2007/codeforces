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

const int N=100007;

struct S
{
    int j,id,t;
};
bool cmp(S L,S R)
{
    return L.j<R.j;
}

int d[N];
vector<S>V[N];
int x[N],h[N];

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
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            V[i].clear();
        }
        V[1].pb({1,0,1});
        V[n].pb({m,k+1,0});
        d[0]=0;
        d[k+1]=inf;
        for(int i=1;i<=k;i++)
        {
            d[i]=inf;
            int a,b,a1,b1;
            cin>>a>>b>>a1>>b1>>h[i];
            V[a].pb({b,i,0});
            V[a1].pb({b1,i,1});
        }
        for(int i=1;i<=n;i++) sort(all(V[i]),cmp);
        for(int i=1;i<=n;i++)
        {
            int mn=inf;
            for(int j=0;j<sz(V[i]);j++)
            {
                if(j>0) mn+=(V[i][j].j-V[i][j-1].j)*x[i];
                if(V[i][j].t==1)
                {
                    if(d[V[i][j].id]!=inf) mn=min(mn,d[V[i][j].id]-h[V[i][j].id]);
                }
                else d[V[i][j].id]=min(d[V[i][j].id],mn);
            }
            mn=inf;
            for(int j=sz(V[i])-1;j>=0;j--)
            {
                if(j!=sz(V[i])-1) mn+=(V[i][j+1].j-V[i][j].j)*x[i];
                if(V[i][j].t==1)
                {
                    if(d[V[i][j].id]!=inf) mn=min(mn,d[V[i][j].id]-h[V[i][j].id]);
                }
                else d[V[i][j].id]=min(d[V[i][j].id],mn);
            }
        }
        if(d[k+1]==inf) cout<<"NO ESCAPE"<<endl;
        else cout<<d[k+1]<<endl;
    }

    return 0;
}