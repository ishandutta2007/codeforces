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

int last[100007];
bool p[100007];
int a[100007];
int L[100007];
vector<int>fac[100007];
int skok[100007][20];


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
        for(int i=2;i<=100000;i++)
        {
            if(p[i]) continue;
            fac[i].pb(i);
            for(int j=2*i;j<=100000;j+=i)
            {
                p[j]=1;
                fac[j].pb(i);
            }
        }
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            L[i]=0;
            for(auto d:fac[a[i]]) L[i]=max(L[i],last[d]);
            for(auto d:fac[a[i]]) last[d]=i;
            L[i]=max(L[i],L[i-1]);
        }
        for(int i=1;i<=n;i++)
        {
           // cout<<L[i]<<" ";
            skok[i][0]=L[i];
            for(int j=1;j<18;j++) skok[i][j]=skok[skok[i][j-1]][j-1];
        }
        //cout<<endl;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int it=17,ans=0;
            while(true)
            {
                bool x=0;
                for(; it>=0; it--)
                {
                    if(skok[r][it]>=l)
                    {
                        x=1;
                        r=skok[r][it];
                        ans+=(1<<it);
                        break;
                    }
                }
                if(!x)
                {
                    cout<<ans+1<<endl;
                    break;
                }
            }
        }

    }
    return 0;
}