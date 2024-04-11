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

int a[507];
int x,n,ans=0;
bool mov()
{
    ans++;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>x)
        {
            swap(a[i],x);
            return 1;
        }
    }
    return 0;
}

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
        cin>>n>>x;
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        while(true)
        {
            bool b=0,c=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]<a[i-1])
                {
                    c=1;
                    if(!mov())
                    {
                        cout<<-1<<endl;
                        b=1;
                        break;
                    }
                    continue;
                }
            }
            if(b) break;
            if(c) continue;
            cout<<ans<<endl;
            break;
        }
    }

    return 0;
}