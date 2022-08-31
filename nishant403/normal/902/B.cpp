#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


const int N =10050;

int a[N],c[N];
vector<int> graph[N];

int dfs(int node,int parent)
{
 int steps = 0;   
    
 if(c[node]!=parent) steps++;   
 
    
  for(auto x : graph[node] )
  {
   steps +=dfs(x,c[node]);   
  }
    
 return steps;  
}

signed main()
{
    fast;
    int n,j,i;
    cin >> n;
    
    for(i=2;i<=n;i++)
    {
        cin >> a[i]; 
       graph[a[i]].push_back(i);
    }
    
    for(i=0;i<n;i++) cin >> c[i+1];
    
    cout << dfs(1,0);
}