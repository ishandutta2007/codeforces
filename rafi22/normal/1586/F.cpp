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

const bool multi=0;

int c[1007][1007];
int ans=0,n,k;

void solve(int l,int r,int x)
{
    if(l>=r) return ;
    ans=max(ans,x);
    int m=(r-l+1)/k+min(1LL,(r-l+1)%k);
    for(int i=l;i<=r;i+=m)
    {
        int j=min(i+m-1,r);
        for(int q=i;q<=j;q++) for(int w=j+1;w<=r;w++) c[q][w]=x;
        solve(i,j,x+1);
    }
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
        cin>>n>>k;
        solve(1,n,1);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) cout<<c[i][j]<<" ";
    }

    return 0;
}