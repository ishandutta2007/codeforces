#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 6010;
int dp[N][N];

void compress(vector<pii> & a)
{
   vi go;
   for(auto x : a) go.pb(x.F),go.pb(x.S);
   sort(go.begin(),go.end());
   go.resize(unique(go.begin(),go.end()) - go.begin());
   
   for(auto & x : a)
       x.F = lower_bound(go.begin(),go.end(),x.F) - go.begin() + 1, 
       x.S = lower_bound(go.begin(),go.end(),x.S) - go.begin() + 1;
}

vi s1[N];
vi s2[N];

int calc(int i,int j)
{
    if(i > j) return 0;
    
    int & res = dp[i][j];
    
    if(res != -1) return res;
    
    int ff = 0;
    
    auto v = upper_bound(s1[i].begin(),s1[i].end(),j) - s1[i].begin();
    
    if(v > 0)
    {
        if(s1[i][v-1] == j) ff = 1;
    }
    
    res = ff;
    
    v = upper_bound(s1[i].begin(),s1[i].end(),j-1) - s1[i].begin();
    
    while(v > 0)
    {
        v--;
        int jj = s1[i][v];
        if(jj < i) break;
        
        res = max(res, calc(i,jj) + ff  + calc(jj+1,j));
    }
    
    auto vv = lower_bound(s2[j].begin(),s2[j].end(),i+1) - s2[j].begin();
    
    while(vv != (int)s2[j].size())
    {
        int ii = s2[j][vv];
        
        if(ii > j) break;
        
        res = max(res,calc(ii,j) + ff + calc(i,ii-1));
        
        vv++;
    }
    
    res = max(res,calc(i+1,j) + ff);
    res = max(res,calc(i,j-1) + ff);
    
    return res;
}

void solve()
{
  int n;
    cin >> n;
    
  vector<pii> a(n);
    f(i,n) cin >> a[i].F >> a[i].S;
    
  compress(a);  
   
  int mx = n + n;
  
  for(int i=0;i<=mx;i++)
      for(int j=0;j<=mx;j++) dp[i][j] = -1;
    
  for(int i=0;i<=mx;i++) s1[i].clear(),s2[i].clear();    
  for(auto x : a) s1[x.F].push_back(x.S),s2[x.S].push_back(x.F);
  for(int i=0;i<=mx;i++) 
      sort(s1[i].begin(),s1[i].end()),sort(s2[i].begin(),s2[i].end());
   
  cout << calc(0,mx) << '\n';
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}