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

int ans = 0;
vector<int> save;

void doo(vector<int> & a,int val)
{
    if(a.size() == 0) return;
    
    int temp =0;
    vi ev;
    vi od;
    for(auto x : a) if(x%2 ==0) ev.pb(x);
    else od.pb(x);
        
    if(od.size() > ans)
    {
        ans = od.size();
        save.clear();
        for(auto x : od) save.pb(val*x);
    }
    for(auto &x : ev) x/=2;
    
    doo(ev,val*2);
}

void solve()
{
  
 int n;
 cin >> n;
    
 int a[n];
 f(i,n) cin >> a[i];
    
 vi s(n);
 f(i,n) s[i] = a[i];
 
 save = s;   
    
 doo(s,1);
    
 unordered_map<int,int> xx;
    
 for(auto x : save) xx[x] =  1;  
    
 cout << n-ans << "\n";
    
  f(i,n)
  {
      if(xx.find(a[i]) == xx.end()) cout<< a[i] <<" ";
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