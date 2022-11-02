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

int skok[200007][20];
int last[200007];
int p[200007];
int pos[200007];
int a[200007];
bool ans[200007];
vector<pair<int,int>>Q[200007];

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
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            pos[p[i]]=i;
        }
        p[0]=p[n];
        for(int i=1;i<=m;i++) cin>>a[i];
        for(int i=1;i<=m;i++)
        {
            skok[i][0]=last[p[pos[a[i]]-1]];
            for(int l=1;l<=17;l++) skok[i][l]=skok[skok[i][l-1]][l-1];
            last[a[i]]=i;
        }
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin>>l>>r;
            Q[r].pb({l,i});
        }
        int mx=0;
        for(int i=1;i<=m;i++)
        {
            int j=i,d=n-1;
            for(int l=17;l>=0;l--)
            {
                if((1<<l)>d) continue;
                d-=(1<<l);
                j=skok[j][l];
            }
            mx=max(mx,j);
            for(auto x:Q[i]) if(x.st<=mx) ans[x.nd]=1;
          //  cout<<d<<" "<<j<<endl;
        }
      //  cout<<endl;
        for(int i=1;i<=q;i++) cout<<ans[i];
    }

    return 0;
}