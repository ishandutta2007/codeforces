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

void solve()
{
    int n,k,x;
    cin >> k;
    
    vector<int> arr[k];
    unordered_map<int,int> mp;
    vi ssum(k,0);
    
    int sum = 0;
    
    f(i,k)
    {
        cin >> n;
        
        f(j,n) 
        {
          cin >> x;
          ssum[i]+=x;  
          arr[i].pb(x);
          mp[x] = i;
        }
        
        sum+=ssum[i];
    }
    
    if(sum%k!=0)
    {
       cout<<"No"; return;  
    } 
    
    sum/=k;
     
    int sz = (1LL<<k);
    
    vector<pii> done[sz];
    vector<bool> vis(k,0);    
      
    unordered_map<int,int> mo;

    for(int i=0;i<k;i++)
    {
       
      for(auto x : arr[i])
      {  
      if(mo.find(x) !=mo.end()) break;

          f(y,k) vis[y] = 0;
    
          int last = i;
          int elm = x;
          int mask = (1LL<<i);

          vector<pii> way;
          
          while(way.size()<k)
          {   
              if( mp.find(sum-(ssum[last]-elm)) == mp.end()) break;

              int v = mp[sum-(ssum[last]-elm)];
            
              if(vis[v] == 1) break;
              vis[v] = 1;
              mask|=(1LL<<v);

              way.pb({sum-(ssum[last]-elm),last});
              elm = sum-(ssum[last]-elm);
              last = v;
          }
     
          if(x == elm && last == i ) 
{
  done[mask] = way;

   for(auto y: way) mo[y.F]=1;
}
      }
        
    }
    
    for(int i=1;i<sz;i++)
{
     
     
      for (int s=i; ; s=(s-1)&i) 
      {
          int a = s;
          int b = (s^i);
 
          if(!done[a].empty() && !done[b].empty())
          {
              done[i] = done[a];
              for(auto z : done[b]) done[i].pb(z);
              break;
          }
          
          if(s == 0) break;
      }

}
    
    if(!done[sz-1].empty()) 
    { 
        cout<<"Yes\n";
        
        vector<pii> final(k);
        
        for(auto x : done[sz-1]) final[mp[x.F]] = x;
        
        f(i,k) cout << final[i].F <<" "<<final[i].S+1<<"\n";
        
    }
    else cout <<"No\n";
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}