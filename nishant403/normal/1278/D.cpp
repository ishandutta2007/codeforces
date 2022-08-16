#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N =5e5+10;
vi g[N];
bool vis[N];
int cnt=  0;
int n;

void dfs(int node)
{
    vis[node] = 1;
    cnt++;
    
    for(auto x : g[node])
        if(!vis[x]) dfs(x);
}
bool tree()
{
   dfs(0);
    
   if(cnt != n) return 0;
    
   int sum =0;
    
   f(i,n) sum+=g[i].size();
    
   if(sum != (n+n-2)) return 0;
   return 1;
}

void solve()
{
  cin >> n;
    
  pair<pii,int> a[n];
  f(i,n) cin >> a[i].F.F >> a[i].F.S;
  f(i,n) a[i].S = i;
    
  sort(a,a+n);
    
  set<pii> st;
    
  st.insert({a[0].F.S,a[0].S});
   
  int ff = 0;

 
  for(int i=1;i<n;i++)
  {
    pii spa = {a[i].F.F,-1}; 
    auto h = st.upper_bound(spa);
     
    while(h!=st.end() && ((*h).F) < a[i].F.S)
    {
        g[a[i].S].pb((*h).S);
        g[(*h).S].pb(a[i].S);
        ff++;
        h++;

        if(ff>n){
cout<<"NO\n";
return;
}
    }
      
    st.insert({a[i].F.S,a[i].S});
  }
    
    
  if(tree()) cout <<"YES\n";
  else cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}