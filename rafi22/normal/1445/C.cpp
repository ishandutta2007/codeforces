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

const bool multi=1;

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
        int p,q,ans=0,s;
        cin>>p>>q;
        vector<int>d;
        int k=2;
        s=sqrt(q);
        while(q>1&&k<=s)
        {
            while(q%k==0)
            {
                d.pb(k);
                q/=k;
            }
            k++;
        }
        if(q>1) d.pb(q);
        int cnt=0,act=1;
        for(int i=0;i<d.size();i++)
        {
            act*=d[i];
            if(i+1==d.size()||d[i]!=d[i+1])
            {
                int n=p;
                while(n%act==0) n/=d[i];
                ans=max(ans,n);
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}