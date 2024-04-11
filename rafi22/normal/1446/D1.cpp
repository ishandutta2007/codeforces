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

int a[200007];
int pref[200007][107];
int last[400007];

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
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            for(int j=1;j<=100;j++) pref[i][j]=pref[i-1][j];
            pref[i][a[i]]++;
        }
        int mx=0,p=0;
        for(int j=1;j<=100;j++)
        {
            if(pref[n][j]>mx)
            {
                mx=pref[n][j];
                p=j;
            }
            else if(pref[n][j]==mx) p=-1;
        }
        if(p==-1)
        {
            cout<<n;
            return 0;
        }
        int ans=0;
        for(int j=1;j<=100;j++)
        {
            if(j==p) continue;
            for(int i=0;i<=2*n;i++) last[i]=inf;
            last[n]=0;
            for(int i=1;i<=n;i++)
            {
                ans=max(ans,i-last[pref[i][p]-pref[i][j]+n]);
                if(last[pref[i][p]-pref[i][j]+n]==inf) last[pref[i][p]-pref[i][j]+n]=i;
            }
        }
        cout<<ans;
    }

    return 0;
}