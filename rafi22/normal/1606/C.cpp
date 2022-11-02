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

int a[17];

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
        k++;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int p=pow(10,a[i]);
            int x=min(k,(ll)pow(10,a[i+1]-a[i])-1);
            k-=x;
            ans+=p*x;
        }
        ans+=(ll)pow(10,a[n])*k;
        cout<<ans<<endl;
    }

    return 0;
}