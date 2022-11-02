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

int p[5007];
int ile[5007];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i];
        int ans=0;
        for(int i=1;i<=n;i++) ile[i]=0;
        for(int i=n;i>0;i--)
        {
            int c=0;
            for(int j=i-1;j>0;j--)
            {
                if(p[j]<p[i]) ans+=c;
                c+=ile[j];
            }
            for(int j=i-1;j>0;j--)
            {
                if(p[j]>p[i]) ile[j]++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}