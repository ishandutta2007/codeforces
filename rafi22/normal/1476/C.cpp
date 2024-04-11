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

int a[100007];
int b[100007];
int c[100007];

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>c[i];
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        int ans=0,act=max(a[2],b[2])-min(a[2],b[2])+1;
        for(int i=2;i<=n;i++)
        {
            ans=max(ans,act+c[i]);
            if(a[i+1]==b[i+1]) act=1;
            else act=max(max(a[i+1],b[i+1])-min(a[i+1],b[i+1])+1,act+c[i]-max(a[i+1],b[i+1])+1+min(a[i+1],b[i+1]));
           // else if(max(a[i+1],b[i+1])<min(a[i],b[i])||max(a[i],b[i])<min(a[i+1],b[i+1])) act=max(a[i+1],b[i+1])-min(a[i+1],b[i+1])+1;

        }
        cout<<ans<<endl;
    }

    return 0;
}