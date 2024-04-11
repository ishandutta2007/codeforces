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

int ile[200007];
int ile1[200007];
int a[200007];
int M[200007];

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
        int n,x;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int mex=0;
        for(int i=n;i>0;i--)
        {
            ile[a[i]]++;
            while(ile[mex]) mex++;
            M[i]=mex;
        }
        vector<int>b;
        for(int i=1;i<=n;i++)
        {
            b.pb(M[i]);
            int c=M[i];
            vector<int>xd;
            mex=0;
           // cout<<i<<endl;
            for(;i<=n;i++)
            {
                xd.pb(a[i]);
                ile1[a[i]]++;
                while(ile1[mex]) mex++;
                if(mex==c) break;
            }
            for(auto x:xd) ile1[x]=0;
        }
        cout<<sz(b)<<endl;
        for(auto x:b) cout<<x<<" ";
        cout<<endl;
        for(int i=0;i<=n;i++) ile[i]=0;
    }

    return 0;
}