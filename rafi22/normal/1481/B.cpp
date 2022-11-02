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
int ans[100007];

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
        int last=k;
        for(int i=1;i<=k;i++)
        {
            int o=-1;
            for(int j=1;j<n;j++)
            {
                if(a[j]<a[j+1])
                {
                    a[j]++;
                    o=j;
                    break;
                }
            }
            ans[i]=o;
            if(ans[i]==-1)
            {
                last=i;
                break;
            }
        }
        if(k>last) cout<<-1<<endl;
        else cout<<ans[k]<<endl;
    }

    return 0;
}