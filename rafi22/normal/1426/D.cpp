#include <bits/stdc++.h>

#define int long long
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

map<int,int> mapa;
int tab[200007];
int pref[200007];

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
        int n,sum=0,ans=0,it=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        mapa[0]=1;
        for(int i=1;i<=n;i++)
        {
            sum+=tab[i];
            pref[i]=sum;
            if(mapa[sum]>0)
            {
                //cout<<i<<endl;
                ans++;
                for(;it<i-1;it++)
                {
                    mapa[pref[it]]--;
                   // cout<<it<<endl;
                }
            }
            mapa[sum]++;
        }
        cout<<ans;
    }

    return 0;
}