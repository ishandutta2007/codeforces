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

const int N=300007;

int a[N],d[N],c[N];
int fib[N];

int ile;
void upd(int i,int x)
{
    ile-=(d[i]!=c[i]);
    c[i]=(c[i]+x+2*mod)%mod;
    ile+=(d[i]!=c[i]);
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
        int n,q,b;
        cin>>n>>q>>mod;
        for(int i=1;i<=n;i++) cin>>a[i];
        fib[1]=1;
        for(int i=2;i<=n;i++) fib[i]=(fib[i-2]+fib[i-1])%mod;
        for(int i=1;i<=n;i++)
        {
            cin>>b;
            a[i]=(a[i]-b+mod)%mod;
        }
        d[1]=(-a[1]+mod)%mod;
        for(int i=2;i<=n;i++) d[i]=(a[i-1]+a[i-2]-a[i]+mod)%mod;
        for(int i=1;i<=n;i++) ile+=(d[i]!=c[i]);
        while(q--)
        {
            char x;
            int l,r;
            cin>>x>>l>>r;
            if(x=='A')
            {
                upd(l,1);
                if(r+1<=n)
                {
                    if(l==r) upd(r+1,-fib[r-l+1]);
                    else upd(r+1,-fib[r-l+1]-fib[r-l]);
                }
                if(r+2<=n) upd(r+2,-fib[r-l+1]);
            }
            else
            {
                upd(l,-1);
                if(r+1<=n)
                {
                    if(l==r) upd(r+1,fib[r-l+1]);
                    else upd(r+1,fib[r-l+1]+fib[r-l]);
                }
                if(r+2<=n) upd(r+2,fib[r-l+1]);
            }
            if(ile==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}