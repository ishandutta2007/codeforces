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

int x[200007],y[200007];

signed main()
{
    mod=mod1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,k,q;
        cin>>n>>m>>k>>q;
        set<int>X,Y;
        for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
        int ans=1;
        for(int i=q;i>0;i--)
        {
            if(sz(X)==n||sz(Y)==m) break;
            if(X.count(x[i])&&Y.count(y[i])) continue;
            ans=ans*k%mod;
            X.insert(x[i]);
            Y.insert(y[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}