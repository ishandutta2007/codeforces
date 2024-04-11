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

const bool multi=0;

int DP[3000007][3];
int inv[3000007];
int silnia[3000007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k) {return silnia[n]*inv[k]%mod*inv[n-k]%mod;}

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
        int n,q;
        cin>>n>>q;
        silnia[0]=1;
        for(int i=1;i<=3*n+1;i++) silnia[i]=silnia[i-1]*i%mod;
        inv[3*n+1]=pot(silnia[3*n+1],mod-2);
        for(int i=3*n;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
        DP[0][0]=n;
        DP[0][1]=n;
        DP[0][2]=n;
        int inv3=pot(3,mod-2);
        for(int i=1;i<=3*n;i++)
        {
            DP[i][0]=((npok(3*n,i+1)-2*DP[i-1][0]-DP[i-1][1])%mod+mod)%mod*inv3%mod;
            DP[i][1]=(DP[i][0]+DP[i-1][0])%mod;
            DP[i][2]=(DP[i][1]+DP[i-1][1])%mod;
        }
        while(q--)
        {
            int x;
            cin>>x;
            cout<<(DP[x][0]+npok(3*n,x))%mod<<endl;
        }
    }

    return 0;
}