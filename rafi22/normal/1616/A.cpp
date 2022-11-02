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

int cnt[107];

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
        memset(cnt,0,sizeof cnt);
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            x=abs(x);
            if(x==0)
            {
                if(cnt[x]==0) ans++;
            }
            else if(cnt[x]<=1) ans++;
            cnt[x]++;
        }
        cout<<ans<<endl;
    }

    return 0;
}