#include <bits/stdc++.h>
 
//#define int long long
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
 
const bool multi=0;
 
bool DP[707][707][2];
bool odw[707][707][2];
bool g[707][707];
int a[707];
 
bool licz(int l,int p,bool k)
{
    if(odw[l][p][k]) return DP[l][p][k];
    odw[l][p][k]=1;
    int r=0;
    if(l==p)
    {
        if(k)
        {
            if(__gcd(a[l],a[l+1])>1) r=1;
        }
        else
        {
            if(__gcd(a[l],a[l-1])>1) r=1;
        }
    }
    else
    {
        int x;
        if(k) x=p+1;
        else x=l-1;
        if(g[x][l]&&licz(l+1,p,0)) r=1;
        for(int i=l+1;i<p;i++)
        {
            if(g[x][i]&&licz(l,i-1,1)&&licz(i+1,p,0)) r=1;
        }
        if(g[x][p]&&licz(l,p-1,1)) r=1;
    }
    DP[l][p][k]=r;
    return r;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(__gcd(a[i],a[j])>1) g[i][j]=1;
            }
        }
        bool ans=0;
        if(licz(2,n,0)) ans=1;
        for(int i=2;i<n;i++)
        {
            if(licz(1,i-1,1)&&licz(i+1,n,0)) ans=1;
        }
        if(licz(1,n-1,1)) ans=1;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 
    return 0;
}