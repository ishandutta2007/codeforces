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
ll mod=1000000033;
int mod1=998244353;

const bool multi=0;

const int N=100007,M=5;

pair<int,int> subsets[N][1<<M];
int id[N][1<<M];
vector<int>X[N];

int l[N],r[N],mid[N];
int cnt[N*(1<<M)];
int ile[N];

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
        vector<pair<pair<int,int>,pair<int,int>>>V;
        vector<pair<int,int>>ord;
        for(int i=1;i<=n;i++)
        {
            vector<int>a(m);
            for(int j=0;j<m;j++) cin>>a[j];
            sort(all(a));
            int w;
            cin>>w;
            ord.pb({w,i});
            for(int x=1;x<(1<<m);x++)
            {
                ll p1=1,p2=1;
                for(int j=0;j<m;j++)
                {
                    if((x&(1<<j)))
                    {
                        subsets[i][x].st=((ll)subsets[i][x].st+(ll)p1*(ll)a[j]%mod)%mod;
                        subsets[i][x].nd=((ll)subsets[i][x].nd+(ll)p2*(ll)a[j]%mod)%mod;
                        p1=p1*1000000007%mod;
                        p2=p2*1000000009%mod;
                    }
                }
                V.pb({subsets[i][x],{i,x}});
            }
        }
        sort(all(V));
        int it=1;
        id[V[0].nd.st][V[0].nd.nd]=it;
        for(int i=1;i<sz(V);i++)
        {
            if(V[i-1].st!=V[i].st) it++;
            id[V[i].nd.st][V[i].nd.nd]=it;
        }
        sort(all(ord));
        for(int i=0;i<n;i++) r[ord[i].nd]=i;
        for(int y=0;y<17;y++)
        {
            for(int i=1;i<=n;i++)
            {
                if(l[i]==r[i]) continue;
                ile[i]=0;
                mid[i]=(l[i]+r[i])/2;
                X[mid[i]].pb(i);
            }
            memset(cnt,0,sizeof cnt);
            for(int i=0;i<n;i++)
            {
                for(int x=1;x<(1<<m);x++) cnt[id[ord[i].nd][x]]++;
                for(auto j:X[i])
                {
                    for(int x=1;x<(1<<m);x++)
                    {
                        if(!(__builtin_popcount(x)&1)) ile[j]-=cnt[id[j][x]];
                        else ile[j]+=cnt[id[j][x]];
                    }
                }
                X[i].clear();
            }
            for(int i=1;i<=n;i++)
            {
                if(l[i]==r[i]) continue;
                if(ile[i]==mid[i]+1) l[i]=mid[i]+1;
                else r[i]=mid[i];
            }
        }
        int ans=2*mod;
        for(int i=0;i<n;i++) if(l[ord[i].nd]<i) ans=min(ans,ord[i].st+ord[l[ord[i].nd]].st);
        if(ans==2*mod) cout<<-1;
        else cout<<ans;
    }

    return 0;
}