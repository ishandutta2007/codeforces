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

const int N =2e5+10;
vi A[N];

void solve()
{
  int n,k;
    cin >> n >> k;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    f(i,n)
    {
        int s = a[i];
        int st = 0;
        
        while(s)
        {
          A[s].pb(st); st++; s>>=1;   
        }
        
        A[0].pb(st);
    }
    
     sort(A[0].begin(),A[0].end());
    
    int ans = 0;
    
    f(i,k) ans+=A[0][i];
    
    
    for(int i=1;i<=(int)2e5;i++)
    {
        int sum =0;
        
      if(A[i].size() >= k)
      {
          sort(A[i].begin(),A[i].end());
          f(j,k) sum+=A[i][j];
              ans=min(ans,sum);
    
      }
    }
    
    cout << ans;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}