#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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
vector<int>p[200007];
int xd[200007];

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
        int n,x,mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            p[x].pb(i);
        }
        vector<int>ord;
        for(int i=1;i<=n;i++)
        {
            for(auto x:p[i]) ord.pb(x);
            mx=max(mx,sz(p[i]));
        }
        int s=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<sz(p[i]);j++)
            {
                xd[(s+mx)%n]=i;
                s++;
            }
        }
        for(int i=0;i<n;i++) a[ord[i]]=xd[i];
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++) p[i].clear();
    }

    return 0;
}