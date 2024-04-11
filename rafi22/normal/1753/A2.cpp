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

int a[200007];

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
        int n,s=0;
        cin>>n;
        vector<int>V;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]!=0) V.pb(i);
        }
        if(sz(V)%2==1)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<pair<int,int>>ans;
        int l=0;
        for(int i=0;i<sz(V);i+=2)
        {
            if(l!=V[i]-1) ans.pb({l+1,V[i]-1});
            if(a[V[i]]==a[V[i+1]])
            {
                if((V[i+1]-V[i])%2) ans.pb({V[i],V[i+1]});
                else
                {
                    ans.pb({V[i],V[i]});
                    ans.pb({V[i]+1,V[i+1]});
                }
            }
            else
            {
                if((V[i+1]-V[i])%2)
                {
                    ans.pb({V[i],V[i]});
                    ans.pb({V[i]+1,V[i+1]});
                }
                else ans.pb({V[i],V[i+1]});
            }
            l=V[i+1];
        }
        if(l!=n) ans.pb({l+1,n});
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}