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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        set<pair<int,int>>S;
        S.insert({-inf,0});
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1]+a[i];
            set<pair<int,int>>::iterator it=--S.end();
            while(true)
            {
                pair<int,int>p=*it;
                if(p.st<pref[i-1]-a[i]) break;
                if(p.nd<i-1&&pref[i-1]-pref[p.nd]==(a[i]^a[p.nd])) ans++;
                it--;
            }
            S.insert({a[i]+pref[i],i});
        }
        cout<<ans;
    }

    return 0;
}