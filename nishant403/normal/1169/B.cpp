#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f(i,n) for(i=1;i<=n;i++)


const int N =3e5+5;
int deg[N];
int edge[2][N];
    
signed main()
{
    fast;
    int i,j,k,n,m;
    
    cin >> n >> m;
    
    int x,y;
    int flag=0,a,b;
    
    f(i,m) 
    {
     cin >> x >> y;   
        
        if(flag==0) { a=x,b=y; flag=1;}
    
      if(x==a) edge[0][y]++;
      if(x==b) edge[1][y]++;
      if(y==a) edge[0][x]++;
      if(y==b) edge[1][x]++;  
        
      deg[x]++;
      deg[y]++;
    }
      
    //check for node a
    for(int i=1;i<=n;i++)
    {
    if(i==a) continue; 
        
        if(deg[a]+deg[i] - edge[0][i] == m) { cout << "YES"; return 0;}    
    }
    
    
    //check for node b
    for(int i=1;i<=n;i++)
    {
    if(i==b) continue;     
   
        if(deg[b]+ deg[i] - edge[1][i] == m) { cout << "YES"; return 0;}   
    }
    
    
    
    
    cout << "NO";
}