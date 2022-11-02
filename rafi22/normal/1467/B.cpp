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

int a[300007];
int n;

bool check(int i)
{
    if(i>1&&i<n)
    {
        if(a[i-1]>a[i]&&a[i+1]>a[i]) return 1;
        if(a[i-1]<a[i]&&a[i+1]<a[i]) return 1;
    }
    return 0;
}

int cnt(int i,int v)
{
    int r1=check(i-1)+check(i+1)+check(i);
    swap(a[i],v);
    int r2=check(i-1)+check(i+1)+check(i);
    swap(a[i],v);
    return r1-r2;
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
        int ans=0,mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]*=2;
        }
        for(int i=1;i<=n;i++) ans+=check(i);
        for(int i=2;i<n;i++)
        {
            mx=max(mx,cnt(i,a[i-2]));
            mx=max(mx,cnt(i,a[i-2]+1));
            mx=max(mx,cnt(i,a[i-2]-1));
            mx=max(mx,cnt(i,a[i-1]));
            mx=max(mx,cnt(i,a[i-1]+1));
            mx=max(mx,cnt(i,a[i-1]-1));
            mx=max(mx,cnt(i,a[i]));
            mx=max(mx,cnt(i,a[i]+1));
            mx=max(mx,cnt(i,a[i]-1));
            mx=max(mx,cnt(i,a[i+1]));
            mx=max(mx,cnt(i,a[i+1]+1));
            mx=max(mx,cnt(i,a[i+1]-1));
            mx=max(mx,cnt(i,a[i+2]));
            mx=max(mx,cnt(i,a[i+2]+1));
            mx=max(mx,cnt(i,a[i+2]-1));
        }
        for(int i=1;i<=n;i++) a[i]=0;
        cout<<ans-mx<<endl;
    }

    return 0;
}