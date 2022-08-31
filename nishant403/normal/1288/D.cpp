#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 3e5+10;
const int M = 512;
pair<int,int> best[M];
int a[N][8];
int n,m;

void solve()
{
    cin >> n >> m;
    f(i,n) f(j,m) cin >> a[i][j];
    
    int mm = (1LL<<m);
    int calc[mm];
    int inv2[M];
    
    f(i,8) inv2[(1<<i)] = i;
    f(j,mm) calc[j] = 1e9+10;
    f(j,mm) best[j].S = -1;
    
    f(i,n)
    {
    for(int j=1;j<mm;j++) 
        calc[j] = min(calc[j&(j-1)],a[i][inv2[j^(j&(j-1))]]);
        
      for(int j=1;j<mm;j++)
       if(calc[j] > best[j].S)
        {
        best[j].S = calc[j];
        best[j].F = i+1;
        }    
        
    }
    
    best[0].F = 1;
    best[0].S = 0;
    
    int full = (1LL<<m)-1;
    
    pair<int,int> ans = {-1,-1};
    int val = -1;
    
    f(i,mm)
    {
       int a = i;
       int b = full^i;
        
       if(min(best[i].S,best[full^i].S) > val)
       {
           val = min(best[i].S,best[full^i].S);
           ans.F = best[i].F;
           ans.S = best[full^i].F;
       }
    }
    
    cout << ans.F <<" "<<ans.S;
    
}

signed main()
{
    fast;
    solve();
}