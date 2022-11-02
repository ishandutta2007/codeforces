#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int tab[300007];

int power_modulo_fast(int a, int b, int m)
{
    int i;
    int result = 1;
    int x = a%m;
    for (i=1; i<=b; i<<=1)
    {
        x %= m;
        if ((b&i) != 0)
        {
            result *= x;
            result %= m;
        }
        x *= x;
    }
    return result;
}
int silnia[300007];
int dwumian(int n,int k)
{
    if(k>n) return 0;
    if(k==0) return 1;
    int gora=silnia[n];
    int dol=(silnia[k]*silnia[n-k])%mod1;
  //  cout<<n<<" "<<k<<endl;
    //cout<<dol<<" "<<gora<<endl;
    gora*=power_modulo_fast(dol,mod1-2,mod1);
    return gora%mod1;
}

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
        silnia[0]=1;
        for(int i=1;i<=300000;i++) silnia[i]=silnia[i-1]*i%mod1;
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=2*n;i++) cin>>tab[i];
        sort(tab+1,tab+1+2*n);
        for(int i=1;i<=n;i++)
        {
            ans+=tab[i+n]-tab[i];
        }
        ans%=mod1;
        ans*=dwumian(2*n,n);
        ans%=mod1;
        cout<<ans<<endl;

    }

    return 0;
}