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

const bool multi=1;

int h[200007];

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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>h[i];
        int l=h[1],p=h[1];
        bool ok=1;
        for(int i=2;i<n;i++)
        {
            if(l-k+1>h[i]+k-1||h[i]>=p+k) ok=0;
            l=max(h[i],l-k+1);
            p=min(p+k-1,h[i]+k-1);
        }
        if(h[n]+k<=l||h[n]>=p+k) ok=0;
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}