

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

const int N =1e6+10;

vi deg(N,0);
vector<pii> edge;
vi check(N,0);
vi redu(N,0);

void solve()
{
 int n,m,a,b;
 cin >> n >> m;
    
 f(i,m)
 {
     cin >> a >> b;
     edge.pb({a,b});
     deg[a]++;
     deg[b]++;
 }
    
 random_shuffle(edge.begin(),edge.end());    
    
 f(i,N) redu[i] = deg[i] - (deg[i]+1)/2;   
    
 int red =m-(n+m+1)/2;    
 
 for(int i=0;i<m;i++) 
 {
  if(red <= 0) break;
     
     if(redu[edge[i].F] > 0 && redu[edge[i].S] > 0) 
     {
      check[i] = -1;
      redu[edge[i].F]--;
      redu[edge[i].S]--;
      red--;
     }
 } 
    
 cout << min(m,(m+n+1)/2) << "\n";   
    
 for(int i=0;i<m;i++)
  if(check[i]!=-1) cout << edge[i].F << " " << edge[i].S<< "\n";   
     
}

signed main()
{
    fast;
    solve();
}