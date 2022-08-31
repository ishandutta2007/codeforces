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

const int N = 2e5+10;
int dsu[N];
int sz[N];
int dp[N];
vector<pii> edge[N];

int ans = 0;

int find(int x)
{
     if(dsu[x] == x) return x;
    return dsu[x] = find(dsu[x]);
}

void merge(int a,int b)
{
  int a1 = find(a);
  int b1 = find(b);
    
 assert(a1!=b1);
    
  if(sz[a1] > sz[b1]) swap(a1,b1);
    
  ans-=dp[a1];
  ans-=dp[b1];  
    
  dp[b1] += (sz[a1]*sz[b1]) + dp[a1];
    
  ans+=dp[b1];   
    
  dsu[a1] = b1;   
  sz[b1]+=sz[a1]; 
    
}

bool comp(const pair<pii,int> & a,const pair<pii,int> & b)
{
  return a.F.S < b.F.S;   
}

void solve()
{
  int n,m,a,b,w;
  cin >> n >> m;
    
    f(i,n-1)
    {
      cin >> a >> b >> w;
      edge[w].pb({a,b});  
    }
    
    f(i,n+10) dsu[i] = i,sz[i] = 1,dp[i]=0;
    
    vector<pair<pii,int> > q(m);
    
    f(i,m)
    {
      cin >> w; 
        q[i].F.F=w;
        q[i].F.S=i;
    }
 
    sort(q.begin(),q.end());
 
    int l = 0;
    
    f(i,m)
    {
        for(int j=l;j<=q[i].F.F;j++) 
        {
          for(auto z : edge[j]) merge(z.F,z.S);  
        }
        
        q[i].S = ans;
        
        l = q[i].F.F+1;
    }
   
    sort(q.begin(),q.end(),comp);
    
    f(i,m) cout << q[i].S <<" ";
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}