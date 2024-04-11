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

int a[200007];
int P[200007];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        int s=accumulate(a+1,a+n+1,0LL);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) P[i]=P[i-1]+a[i];
        if(s+(n-2)*a[n]<0||s+(n-2)*a[1]>0)
        {
            cout<<"INF"<<endl;
            continue;
        }
        int ans=-inf;
        //wszystkie do 1
        ans=max(ans,a[1]*(P[n]-P[1])-a[1]*(s+(n-2)*a[1]));
        //wszystkie do n
        ans=max(ans,a[n]*(P[n-1])-a[n]*(s+(n-2)*a[n]));
        for(int i=1;i<n;i++)
        {
            int X=a[1]*(P[n]-P[i])+a[n]*(P[i]-P[1]);
            int Y=s+(n-1-i)*a[1]+(i-1)*a[n];
            int l=-a[i+1],r=-a[i]-1;
            if(l<=r)
            {
                if(Y<0) ans=max(ans,X+Y*l);
                else ans=max(ans,X+Y*r);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}