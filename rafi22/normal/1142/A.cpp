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

int x=inf,y=-inf,n,k;

void solve(int d)
{
    for(int i=0;i<=n;i++)
    {
        if(d+i*k<=0||d+i*k>n*k) continue;
        int l=d+i*k;
       // cout<<l<<" "<<__gcd(n*k,l)<<endl;
        x=min(x,n*k/__gcd(n*k,l));
        y=max(y,n*k/__gcd(n*k,l));
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
        int a,b;
        cin>>n>>k>>a>>b;
        solve(b+1-(a+1));
        solve(b+1-(k-a+1));
        solve((k-b+1)-(a+1));
        solve((k-b+1)-(k-a+1));
       // cout<<x<<" "<<y<<endl;
        cout<<x<<" "<<y<<endl;
    }

    return 0;
}