#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

unordered_map<int,int>ile;

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
        int n,p,k,ans=0,a;
        cin>>n>>p>>k;
        ile.reserve(n+2);
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            int x=((a*a%p)*(a*a%p)%p-k*a%p+p)%p;
            ans+=ile[x];
            ile[x]++;
        }
        cout<<ans;
    }

    return 0;
}