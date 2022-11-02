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
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int M=307,N=57,Q=10000007;
int n,m;

ll ac[M*M];
int ax[M*M];
int o[N],s[N];
int q[Q];

int Find(int v)
{
    if(o[v]==v) return v;
    return o[v]=Find(o[v]);
}
void Union(int u,int v)
{
    if(s[u]>s[v]) swap(u,v);
    o[u]=v;
    s[v]+=s[u];
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
        cin>>n>>m;
        vector<pair<int,pair<int,int>>>E(m),E1;
        for(int i=0;i<m;i++) cin>>E[i].nd.st>>E[i].nd.nd>>E[i].st;
        set<pair<int,int>>S;
        int it=0;
        S.insert({0,++it});
        for(int i=0;i<m;i++)
        {
            S.insert({E[i].st,++it});
            for(int j=0;j<i;j++)
            {
                S.insert({(E[i].st+E[j].st)/2,++it});
                S.insert({(E[i].st+E[j].st)/2+1,++it});
            }
        }
        for(auto X:S)
        {
            int x=X.st;
           // cout<<"XD"<<endl;
            for(int i=1;i<=n;i++)
            {
                o[i]=i;
                s[i]=1;
            }
            E1=E;
            for(int i=0;i<m;i++)
            {
                if(E[i].st-x<=0)
                {
                    E1[i].st=x-E[i].st;
                    E1[i].nd.st=-E1[i].nd.st;
                }
                else E1[i].st-=x;
            }
            sort(all(E1));
            int c=0;
            for(auto y:E1)
            {
                int w=y.st,u=y.nd.st,v=y.nd.nd;
                bool flip=0;
                if(u<0)
                {
                    flip=1;
                    u=-u;
                }
                u=Find(u),v=Find(v);
                if(u!=v)
                {
                    c+=w;
                    Union(u,v);
                  /*  if(x==3)
                    {
                        cout<<flip<<" "<<w<<endl;
                        cout<<w+x<<" "<<x-w<<endl;
                    }*/
                    if(!flip) ac[X.nd]+=(ll)w+x;
                    else ac[X.nd]+=(ll)-(x-w);
                    if(!flip) ax[X.nd]--;
                    else ax[X.nd]++;
                }
            }
           // cout<<x<<" "<<c<<endl;
        }
        int p,k,a,b,c;
        ll xo=0;
        cin>>p>>k>>a>>b>>c;
        for(int i=1;i<=k;i++)
        {
            if(i<=p) cin>>q[i];
            else q[i]=((ll)q[i-1]*(ll)a+(ll)b)%(ll)c;
            int j=(*(--S.lower_bound({q[i],mod}))).nd;
            ll w=ac[j]+(ll)q[i]*(ll)ax[j];
          //  cout<<q[i]<<" "<<(*(--S.lower_bound({q[i],mod}))).st<<endl;
        //    cout<<ac[j]<<" "<<ax[j]<<endl;
            //cout<<w<<endl;
            xo^=w;
        }
        cout<<xo<<endl;
    }

    return 0;
}