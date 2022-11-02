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

bool p[1000007];
int L[200007];
int R[200007];
int a[200007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(p[i]) continue;
        for(int j=2*i;j<=1000000;j+=i) p[j]=1;
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,e;
        cin>>n>>e;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                if(i-e>0) L[i]=L[i-e]+1;
                else L[i]=1;
            }
            else L[i]=0;
         //   cout<<L[i]<<" ";
        }
        //cout<<endl;
        for(int i=n;i>0;i--)
        {
            if(a[i]==1)
            {
                if(i+e<=n) R[i]=R[i+e]+1;
                else R[i]=1;
            }
            else R[i]=0;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=0;
            if(i-e>0) x=L[i-e];
            int y=0;
            if(i+e<=n) y=R[i+e];
            if(!p[a[i]]) ans+=x*y+x+y;
        }
        cout<<ans<<endl;
    }

    return 0;
}