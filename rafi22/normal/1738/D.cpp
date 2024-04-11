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

int b[100007];
vector<int>x[100007];

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
        int k=0;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            if(b[i]>i) k=max(k,i);
            x[b[i]].pb(i);
        }
        int l=0;
        if(sz(x[n+1])>0) l=n+1;
        cout<<k<<endl;
        while(true)
        {
            for(auto i:x[l])
            {
                if(sz(x[i])==0) cout<<i<<" ";
            }
            int nx=-1;
            for(auto i:x[l])
            {
                if(sz(x[i])>0) nx=i;
            }
            if(nx==-1) break;
            cout<<nx<<" ";
            l=nx;
        }
        cout<<endl;
        for(int i=0;i<=n+1;i++) x[i].clear();
    }

    return 0;
}