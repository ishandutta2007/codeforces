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

vector<vector<int>>V;
vector<vector<int>>P;
vector<int>X;
bool is[40];
int n,b,p,m,K,M=1;
int ans;

void bt(int I,int mx,int ile,int mn)
{
    if(I==sz(X))
    {
        if(ile*m>b) return ;
        int k=min(K,(b-ile*m)/p);
        int act=1;
        for(int i=0;i<sz(X);i++)
        {
            if(sz(P[i])>0) act+=P[i][0];
            if(!is[i]) act*=X[i];
        }
        act*=mn;
        int l=0,r=1000000000000000000,sr,res=0;
        while(l<=r)
        {
            sr=(l+r)/2;
            int mul=1,cnt=0,sum=0;
            for(int i=0;i<sz(X);i++)
            {
                if(mul>1)
                {
                    int t=sr/(M-M/mul)+min(1LL,sr%(M-M/mul));
                    if(sz(V[i])>0&&V[i].back()>=t)
                    {
                        int j=lower_bound(all(V[i]),t)-V[i].begin();
                        cnt+=sz(V[i])-j;
                        sum+=P[i][j]*(M-M/mul);
                    }
                }
                if(!is[i]) mul*=X[i];
            }
            if(cnt>=k)
            {
                res=act+sum-(cnt-k)*sr;
                l=sr+1;
            }
            else r=sr-1;
        }
        ans=max(ans,res);
        return ;
    }
    if(X[I]>mx)
    {
        is[I]=1;
        bt(I+1,mx,ile+1,mn*X[I]);
        is[I]=0;
    }
    bt(I+1,max(mx,X[I]),ile,mn);
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
        cin>>n>>b>>p>>m;
        vector<int>t;
        for(int i=1;i<=n;i++)
        {
            char c;
            int x;
            cin>>c>>x;
            if(c=='*')
            {
                if(x==1) continue;
                M*=x;
                sort(all(t));
                vector<int>p(sz(t));
                if(sz(t)>0)
                {
                    p[sz(t)-1]=t[sz(t)-1];
                    for(int i=sz(t)-2;i>=0;i--) p[i]=p[i+1]+t[i];
                }
                V.pb(t);
                X.pb(x);
                P.pb(p);
                t.clear();
            }
            else
            {
                t.pb(x);
                if(sz(V)>0) K++;
            }
        }
        sort(all(t));
        vector<int>p(sz(t));
        if(sz(t)>0)
        {
            p[sz(t)-1]=t[sz(t)-1];
            for(int i=sz(t)-2;i>=0;i--) p[i]=p[i+1]+t[i];
        }
        V.pb(t);
        X.pb(1);
        P.pb(p);
        bt(0,1,0,1);
        cout<<ans;
    }

    return 0;
}