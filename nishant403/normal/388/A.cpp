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


signed main()
{
Fast;    
    
  int n,x;
    cin >> n;
    
    int a[n];
    
    f(i,n) cin >> a[i];
    
    sort(a,a+n);
    
    int ans = 0;
    int cur = 0;
    int total = 0;
    
    while(total < n)
    {
    cur = 0;
        
    for(int i=0;i<n;i++)
     if(a[i]==-1) continue;
     else 
    {
      if(a[i] >= cur )  
      { 
        cur++;
        total++;
        a[i] = -1;  
      }
    }
     
        ans++;
    }
    
    cout << ans;
}