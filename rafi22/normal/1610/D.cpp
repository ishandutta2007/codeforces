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

const bool multi=0;

int p[200007];
int ile[40];

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
        p[0]=1;
        for(int i=1;i<=n;i++) p[i]=p[i-1]*2%mod;
        int a=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            int c=0;
            while(x%2==0)
            {
                c++;
                x/=2;
            }
            ile[c]++;
            if(c!=0) a++;
        }
        int ans=(p[n]-p[a]+mod)%mod;
        int sum=0;
        for(int i=30;i>0;i--)
        {
            if(ile[i]>0)ans=(ans+p[sum]%mod*(p[ile[i]-1]-1+mod)%mod)%mod;
            sum+=ile[i];
        }
        cout<<ans;
    }

    return 0;
}