#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

bool p[100007];
int ile[100007];
vector<int>prime;
set<int> res;

int ask(int t,int a)
{
    if(t==1) cout<<"A "<<a<<endl;
    else cout<<"B "<<a<<endl;
    int x;
    cin>>x;
    return x;
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
        int n;
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            if(p[i]) continue;
            prime.pb(i);
            ile[i]=1;
            for(int j=2*i;j<=n;j+=i)
            {
                if(!p[j]) ile[i]++;
                p[j]=1;
            }
        }
       // cout<<sz(prime)<<endl;
        int s=sqrt(sz(prime)),last=n;
        for(int i=0;i<sz(prime);i+=s)
        {
            int sum=0;
            for(int j=i;j<min(sz(prime),i+s);j++)
            {
                sum+=ile[prime[j]];
                int x=ask(2,prime[j]);
                if(x>ile[prime[j]]) res.insert(prime[j]);
            }
            int x=ask(1,1);
            //cout<<sum<<endl;
            if(last-x!=sum)
            {
                for(int j=i; j<min(sz(prime),i+s); j++)
                {
                    if(ask(1,prime[j])) res.insert(prime[j]);
                }
            }
            last=x;
        }
        int ans=1;
        for(auto p:res)
        {
            int x=p;
            while(x*p<=n&&ask(1,x*p)==1) x*=p;
            ans*=x;
        }
        cout<<"C "<<ans<<endl;
    }

    return 0;
}