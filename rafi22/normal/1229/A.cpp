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

int a[7007];
int b[7007];
int ile[7007];
bool is[7007][7007];
bool nie[7007];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int x=(a[j]|a[i]);
                if(x!=a[j]) is[i][j]=1;
                ile[i]+=is[i][j];
            }
        }
        int ans=0;
        for(int i=n;i>1;i--)
        {
            bool c=0;
            for(int j=1;j<=n;j++)
            {
                if(nie[j]||ile[j]<i-1) continue;
                nie[j]=1;
                for(int l=1;l<=n;l++) ile[l]-=is[l][j];
                c=1;
                break;
            }
            if(!c)
            {
                for(int j=1;j<=n;j++) if(!nie[j]) ans+=b[j];
                break;
            }
        }
        cout<<ans;
    }

    return 0;
}