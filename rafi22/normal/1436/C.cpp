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
        int n,x,pos,ans=1;
        cin>>n>>x>>pos;
        int l=0,p=n,sr;
        int w=n-x,m=x-1;
        while(l<p)
        {
            sr=(l+p)/2;
            if(sr>pos)
            {
                ans*=w;
                ans%=mod;
                w--;
                n--;
                p=sr;
            }
            else l=sr+1;
            if(sr<pos)
            {
                ans*=m;
                ans%=mod;
                m--;
                n--;
            }
        }
        n--;
        while(n>0)
        {
            ans*=n;
            ans%=mod;
            n--;
        }
        cout<<ans<<endl;
    }

    return 0;
}