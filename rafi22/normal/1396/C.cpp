#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int tab[1000007];
int p[1000007];
int q[1000007];
int l[1000007];
int r[1000007];

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
        int n,r1,r2,r3,d;
        cin>>n>>r1>>r2>>r3>>d;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++)
        {
            p[i]=tab[i]*r1+r3;
            q[i]=min((tab[i]+2)*r1,r2+r1);
        }
        l[0]=-d;
        r[n+1]=-d;
        r[n]=min(p[n],q[n]+2*d);
        for(int i=n-1;i>0;i--) r[i]=r[i+1]+2*d+min(p[i],q[i]);
        l[1]=p[1];
        for(int i=2;i<=n;i++) l[i]=min(l[i-1]+d+p[i],l[i-2]+4*d+min(p[i-1],q[i-1])+min(p[i],q[i]));
        int ans=inf;
        for(int i=1;i<=n;i++) ans=min(ans,l[i]+r[i+1]+d);
        cout<<ans;
    }

    return 0;
}