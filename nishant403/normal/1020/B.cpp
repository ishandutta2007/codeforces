#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
    fast;
    int n,j,i;
    cin >> n;
    
    int a[n+1];
    
    for(i=1;i<=n;i++) cin >> a[i];
    
    for(i=1;i<=n;i++)
    {
     int x = i;   
     vector<int> vis(n+1,0);
       
       while(1) 
       {
        if(vis[x]==1) {cout<< x <<" "; break; }   
        vis[x]=1;
        x=a[x];   
       }
    }
    
}