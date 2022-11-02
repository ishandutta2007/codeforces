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

const int N=200007;

int a[N];
int DP[N];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

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
        int n,k=0,c=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]) k++;
        }
        for(int i=1;i<=n-k;i++) if(a[i]==1) c++;
        for(int i=1;i<=c;i++)
        {
            int p=i*i%mod*pot((n*(n-1)/2)%mod,mod-2)%mod;
            DP[i]=(DP[i-1]+pot(p,mod-2))%mod;
        }
        cout<<DP[c]<<endl;
    }

    return 0;
}