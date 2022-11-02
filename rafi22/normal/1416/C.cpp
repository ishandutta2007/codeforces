#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int tab[300007];
int mask[300007];

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
        int n,x=0;
        ll ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        vector <pair<int,int> > v;
        for(int i=30;i>=0;i--)
        {
            v.clear();
            for(int j=1;j<=n;j++) v.pb({mask[j],j});
            //for(int j=1;j<=n;j++) cout<<mask[j]<<" ";
            //cout<<endl;
            sort(v.begin(),v.end());
            ll inv=0,inv1=0,one=0;
            for(int j=0;j<n;j++)
            {
                if(j>0&&v[j].st!=v[j-1].st) one=0;
                int xd=(tab[v[j].nd]&(1<<i));
                if(xd>0) one++;
                else inv+=one;
            }
            one=0;
            for(int j=0;j<n;j++)
            {
                if(j>0&&v[j].st!=v[j-1].st) one=0;
                int xd=(tab[v[j].nd]&(1<<i));
                if(xd==0) one++;
                else inv1+=one;
            }
            if(inv1<inv)
            {
                x|=(1<<i);
                for(int j=1;j<=n;j++)
                {
                    int xd=(tab[j]&(1<<i));
                    if(xd==0) mask[j]|=(1<<i);
                }
            }
            else
            {
                for(int j=1;j<=n;j++)
                {
                    int xd=(tab[j]&(1<<i));
                    if(xd>0) mask[j]|=(1<<i);
                }
            }
            ans+=min(inv,inv1);
        }
        cout<<ans<<" "<<x<<endl;
    }
    return 0;
}