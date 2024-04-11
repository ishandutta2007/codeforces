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
int b[200007];
int po[200007];
int pos[200007];

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
        int n,k,ans=1;
        cin>>n>>k;
        set<int>act;
        act.insert(0);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            po[a[i]]=i;
            act.insert(i);
        }
        act.insert(n+1);
        for(int i=1;i<=k;i++)
        {
            cin>>b[i];
            b[i]=po[b[i]];
            pos[b[i]]=i;
        }
        for(int i=1;i<=k;i++)
        {
            int l=*(--act.lower_bound(b[i]));
            int p=*act.upper_bound(b[i]);
            if(l!=0&&pos[l]<i)
            {
                act.erase(l);
                if(p!=n+1&&pos[p]<i) ans=ans*2%mod1;
            }
            else
            {
                if(p!=n+1&&pos[p]<i) act.erase(p);
                else ans=0;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<=n+1;i++)
        {
            pos[i]=0;
            po[i]=0;
        }
    }

    return 0;
}