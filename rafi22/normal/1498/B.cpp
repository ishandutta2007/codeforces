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

int a[200007];
int cnt[35];
int space[35];

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
        int n,w;
        cin>>n>>w;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cnt[(int)log2(a[i])]++;
        }
        int take=0,ans=0;
        while(take!=n)
        {
            memset(space,0,sizeof space);
            for(int j=30;j>=0;j--)
            {
                if((w&(1<<j))>0) space[j]++;
                int x=min(space[j],cnt[j]);
                take+=x;
                cnt[j]-=x;
                space[j]-=x;
                if(j>0) space[j-1]+=2*space[j];
            }
            ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}