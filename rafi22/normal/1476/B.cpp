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
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int a[107];

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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        int l=0,r=100000000000000,sr,res=inf;
        while(l<=r)
        {
            sr=(l+r)/2;
            int sum=a[1]+sr;
            bool ok=1;
            for(int i=2;i<=n;i++)
            {
                if(100*a[i]>k*sum) ok=0;
                sum+=a[i];
            }
            if(ok)
            {
                res=sr;
                r=sr-1;
            }
            else l=sr+1;
        }
        cout<<res<<endl;
    }

    return 0;
}