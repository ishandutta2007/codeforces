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

vector <pair<int,bool> > vec;

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
        silnia[1]=1;
        for(int i=2;i<=300000;i++)
        {
            silnia[i]=(silnia[i-1]*i)%mod1;
        }
        int n,k,l,r,ans=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>l>>r;
            vec.push_back({l,0});
            vec.push_back({r,1});
        }
        sort(vec.begin(),vec.end());
        int act=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].nd==0)
            {
                //cout<<act<<endl;
                ans+=dwumian(act,k-1);
                ans%=mod1;
                act++;
            }
            else
            {
                act--;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}