#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 3e5+10;
int dp[N][3];
int n;
pii a[N];
    
const int inf = (int)1e18+10;

int go(int id,int num)
{
    if(id==n-1) return 0;
    if(dp[id][num-a[id].F] != -1) return dp[id][num-a[id].F];
    
    int ans = inf;
    
    if(num < a[id+1].F || num > a[id+1].F+2)
    {
        f(j,3) ans = min(ans,go(id+1,a[id+1].F+j)+(a[id+1].S*j));
    }
    else if(num == a[id+1].F)
    {
      ans=min(ans,go(id+1,a[id+1].F+1)+(a[id+1].S*1));
      ans=min(ans,go(id+1,a[id+1].F+2)+(a[id+1].S*2));    
    }
    else if(num == a[id+1].F+1)
    {
     ans=min(ans,go(id+1,a[id+1].F));
     ans=min(ans,go(id+1,a[id+1].F+2)+(a[id+1].S*2));       
    }
    else if(num == a[id+1].F+2)
    {
     ans=min(ans,go(id+1,a[id+1].F));
     ans=min(ans,go(id+1,a[id+1].F+1)+a[id+1].S);      
    }

    return dp[id][num-a[id].F] = ans;
}

void solve()
{ 
    cin >> n;
    
    f(i,n) cin >> a[i].F >> a[i].S;
    
    f(i,n) f(j,3) dp[i][j] = -1;
    
    int ans=inf;
    
    f(j,3) ans=min(ans,go(0,a[0].F+j)+(a[0].S*j));
    
    cout<<ans<<"\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}