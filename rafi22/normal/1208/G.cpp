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

int phi[1000007];
bool p[1000007];

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
        int n,k;
        cin>>n>>k;
        if(k==1)
        {
            cout<<3;
            return 0;
        }
        for(int i=2;i<=n;i++) phi[i]=1;
        for(int i=2;i<=n;i++)
        {
            if(p[i]) continue;
            phi[i]=i-1;
            for(int j=2*i;j<=n;j+=i)
            {
                p[j]=1;
                int x=1,y=j;
                while(y%i==0)
                {
                    x*=i;
                    y/=i;
                }
                phi[j]*=(x-x/i);
            }
        }
        vector<int>V;
        for(int i=3;i<=n;i++) V.pb(phi[i]);
        sort(all(V));
        int ans=2;
        for(int i=0;i<k;i++) ans+=V[i];
        cout<<ans;
    }

    return 0;
}