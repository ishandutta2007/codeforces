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
 
const int N=1e5+5;
 
vector<int> v[N];
int deg[N];
 
signed main()
{
    fast;
   
 int n,m;
 cin >> n >> m;
 
  f(i,m)
  {
  int a,b;
  cin >> a >> b;
  v[b].pb(a);
  deg[a]++;
 }
 
 priority_queue<int> q;
 f(i,n)
  if(deg[i+1] == 0) q.push(i+1);
 
 vector<int> ans;
 
 while(!q.empty())
  {
  int cur = q.top();
  q.pop();
  ans.pb(cur);
  for(int x:v[cur]){
   deg[x]--;
   if(deg[x] == 0) q.push(x);
  }
 }
 
 reverse(ans.begin(),ans.end());
    
 vector<int> go(n+1,0);
 for(int i=0;i<n;i++) go[ans[i]] = i + 1; 
 for(int i=1;i<=n;i++) cout << go[i]<< ' ';
}