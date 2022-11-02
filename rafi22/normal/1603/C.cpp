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
const int S=320;

const bool multi=1;

int a[100007];
int ile[100007];
int nile[100007];

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
        mod=mod1;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        vector<int>V,nV;
        for(int i=n;i>0;i--)
        {
            for(auto k:V)
            {
                int x=a[i]/k+min(1LL,a[i]%k);
                ans=(ans+(x-1)*ile[k]%mod*i)%mod;
                int nk=a[i]/x;
                if(nile[nk]==0) nV.pb(nk);
                nile[nk]+=ile[k];
                ile[k]=0;
            }
            if(nile[a[i]]==0) nV.pb(a[i]);
            nile[a[i]]++;
            V.clear();
            for(auto k:nV)
            {
                V.pb(k);
                ile[k]=nile[k];
                nile[k]=0;
            }
            nV.clear();
        }
        for(auto k:V) ile[k]=0;
        cout<<ans<<endl;
    }

    return 0;
}