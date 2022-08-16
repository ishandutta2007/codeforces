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
     
    struct custom_hash
    {
     static uint64_t splitmix64(uint64_t x) 
     {
      x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

    void solve()
    {
      int n,k,x;
        cin >> n >> k;
        
      deque<int> d;
      unordered_map<int,int,custom_hash> mp;
        
      while(n--)  
      {
          cin >> x;
          
          if(mp.find(x) != mp.end()) continue;
                   
          if(d.size() == k)
          {
              mp.erase(d.back());
              d.pop_back();
          }
          
          mp[x] = 1;
          d.push_front(x);    
          
      }
        
      cout << d.size() << '\n';
        
      while(!d.empty())
      {
        cout<<d.front() <<" "; d.pop_front();   
      }
        
    }
     
    signed main()
    {
        fast;
        
        int t = 1;
        
    //    cin >> t;
        
        while(t--)
            
        solve();
    }