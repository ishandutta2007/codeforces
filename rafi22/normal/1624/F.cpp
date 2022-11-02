#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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
        int n,ans=0,k=1,c=0,last;
        cin>>n;
        for(int i=9;i>=0;i--)
        {
            if(ans+(1<<i)>=n) continue;
            for(int j=1;j<=n;j++)
            {
                if(j*n-c>=(ans+(1<<i)))
                {
                    k=j;
                    break;
                }
            }
            int d=k*n-c-(ans+(1<<i)),x;
            c+=d;
            if(d!=0)
            {
                cout<<"+ "<<d<<endl;
                cin>>x;
                last=x;
            }
            else x=last;
            if(x>=k) ans+=1<<i;
        }
        cout<<"! "<<ans+c<<endl;
    }

    return 0;
}