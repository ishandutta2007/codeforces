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
        int n,ans=inf,c1,c0;
        string a,b;
        cin>>n>>a>>b;
        //ans%2==0
        c1=0,c0=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                if(a[i]=='1') c1++;
                else c0++;
            }
        }
        if((c0+c1)%2==0&&c0==c1) ans=min(ans,c0+c1);
        //cout<<c0<<" "<<c1<<endl;
        //ans%2==1
        c1=0,c0=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[i])
            {
                if(a[i]=='1') c1++;
                else c0++;
            }
        }
        //cout<<c0<<" "<<c1<<endl;
        if((c0+c1)%2==1&&c1==c0+1) ans=min(ans,c0+c1);
        if(ans==inf) cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}