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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve()
{
   int n;
    cin >> n;
    
   pii a[n];
    f(i,n) cin >> a[i].F >> a[i].S;
    
   vi go;
   f(i,n) if(a[i].S > 0) go.pb(a[i].S);
       
   sort(go.begin(),go.end());
   go.resize(unique(go.begin(),go.end()) - go.begin());    
   unordered_map<int,int> mp,imp;  
    
   f(i,go.size()) mp[go[i]] = i, imp[i] = go[i];
     
   FenwickTree cnt(n+10),ssum(n+10); 
   set<int> fire;     
    
   f(i,n)
   {
       int id = -1;
       
       if(a[i].S > 0) id = mp[a[i].S];
       else id = mp[-a[i].S];
       
       if(a[i].S > 0) 
       {
           cnt.add(id,1);
           ssum.add(id,a[i].S);
           
           if(a[i].F == 0) fire.insert(a[i].S);
       }
       else
       {
           cnt.add(id,-1);
           ssum.add(id,a[i].S);
           
           if(a[i].F == 0) fire.erase(-a[i].S);
       }
       
       int tot = cnt.sum(n);
       int req = fire.size(); 
       
       int l = 0;
       int r = n-1;
       int res = -1;
       
       while( l <= r )
       {
           int mid = (l + r)/2;
           
           int v = cnt.sum(mid);
           
           if(v <= req)
           {
               res = mid;
               l = mid + 1;
           }
           else r = mid - 1;
       }
       
       int s1 = ssum.sum(n);
       if(res != -1) s1 -= ssum.sum(res);
       
       if(req == 0)
       {
           s1-= imp[res + 1];
       }
       else if((*fire.rbegin()) < imp[res+1])
       {
           s1-=imp[res+1];
           s1 += (*fire.rbegin());
       }
       
       
       int sum = ssum.sum(n);
       
       cout << sum + s1 << '\n';
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