#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

map<int,int> graph[1005];

signed main ()
{
  Fast;

  int n,m,a,b;
  cin >> n >> m;

   pii v[n];

  f(i,n) { cin >> v[i].F; v[i].S = i+1; }

 f(i,m)
 {
     cin >> a >> b;
     graph[a][b] = 1;
     graph[b][a] = 1;
 }
 
 sort(v,v+n);

 int ans = 0;
 
 for(int i=0;i<n;i++)
 {
  ans+=v[i].F*(graph[v[i].S].size());     
  for(auto x : graph[v[i].S]) graph[x.F].erase(v[i].S);    
 }
 
 cout << ans;

}