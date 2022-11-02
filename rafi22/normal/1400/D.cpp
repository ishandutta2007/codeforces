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
int a[3007];
int cnt1[3007];
int cnt2[3007];

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
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cnt1[j]=0;
                cnt2[j]=0;
            }
            for(int j=n;j>i+1;j--) cnt2[a[j]]++;
            int act=0;
            for(int j=i+2;j<=n;j++)
            {
                cnt2[a[j]]--;
                act-=cnt1[a[j]];
                cnt1[a[j-1]]++;
                act+=cnt2[a[j-1]];
                if(a[i]==a[j]) ans+=act;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}