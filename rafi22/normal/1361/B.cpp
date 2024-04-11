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
int inf=1000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int a[1000007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

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
        int n,p;
        cin>>n>>p;
        vector<int>v1,v2;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int balance=0,last=-1;
        for(int i=n;i>0;i--)
        {
            int k=a[i];
            if(last!=-1)
            {
                int pot=1;
                if(p>1)
                {
                    for(int j=0; j<last-k; j++)
                    {
                        pot*=p;
                        if(pot>1000000)
                        {
                            pot=inf;
                            break;
                        }
                    }
                }
                if(balance>=0) balance=min(pot*balance,inf);
                else balance=max(pot*balance,-inf);
            }
            if(balance<=0)
            {
                v1.pb(k);
                balance++;
            }
            else
            {
                v2.pb(k);
                balance--;
            }
            last=k;
        }
        int ans=0;
        if(balance>=0)
        {
            for(auto x:v1) ans=(ans+pot(p,x))%mod;
            for(auto x:v2) ans=(ans-pot(p,x)+mod)%mod;
        }
        else
        {
            for(auto x:v2) ans=(ans+pot(p,x))%mod;
            for(auto x:v1) ans=(ans-pot(p,x)+mod)%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}