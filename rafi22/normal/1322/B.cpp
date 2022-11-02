#include <bits/stdc++.h>

//#define int long long
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

int a[400007];

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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int j=25;j>=0;j--)
        {
            sort(a+1,a+n+1);
            int ile=0;
            for(int i=1;i<=n;i++)
            {
                int l=1,r=n,sr,L=n+1,R=0;
                while(l<=r)
                {
                    sr=(l+r)/2;
                    if(a[i]+a[sr]>=(1<<j))
                    {
                        if(a[i]+a[sr]<(1<<(j+1)))
                        {
                            L=sr;
                            r=sr-1;
                        }
                        else r=sr-1;
                    }
                    else l=sr+1;
                }
                l=1,r=n;
                while(l<=r)
                {
                    sr=(l+r)/2;
                    if(a[i]+a[sr]>=(1<<j))
                    {
                        if(a[i]+a[sr]<(1<<(j+1)))
                        {
                            R=sr;
                            l=sr+1;
                        }
                        else r=sr-1;
                    }
                    else l=sr+1;
                }
                if(i>=L&&i<=R) ile+=max(0,R-L);
                else ile+=max(0,R-L+1);
                L=n+1,R=0;
                l=1,r=n;
                while(l<=r)
                {
                    sr=(l+r)/2;
                    if(a[i]+a[sr]>=(1<<(j+1))+(1<<j))
                    {
                        if(a[i]+a[sr]<(1<<(j+2)))
                        {
                            L=sr;
                            r=sr-1;
                        }
                        else r=sr-1;
                    }
                    else l=sr+1;
                }
                l=1,r=n;
                while(l<=r)
                {
                    sr=(l+r)/2;
                    if(a[i]+a[sr]>=(1<<(j+1))+(1<<j))
                    {
                        if(a[i]+a[sr]<(1<<(j+2)))
                        {
                            R=sr;
                            l=sr+1;
                        }
                        else r=sr-1;
                    }
                    else l=sr+1;
                }
                if(i>=L&&i<=R) ile+=max(0,R-L);
                else ile+=max(0,R-L+1);
            }
            ile/=2;
            //cout<<ile<<endl;
            if(ile%2) ans+=(1<<j);
            for(int i=1;i<=n;i++) if(a[i]>=(1<<j)) a[i]-=(1<<j);
        }
        cout<<ans;
    }

    return 0;
}