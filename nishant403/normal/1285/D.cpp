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

int get(vector<int> & a,int bt)
{
    if(bt == -1) return 0;
    
    vector<int> a1,b1;
    
    int num = (1LL<<bt);
    
    for(auto x : a) 
        if((x/num)%2 == 1) a1.pb(x);
        else b1.pb(x);
        
    if(a1.size() == 0) return get(b1,bt-1); 
    if(b1.size() == 0) return get(a1,bt-1);
        
    return num + min(get(a1,bt-1),get(b1,bt-1));    
}

void solve()
{
  int n;
  cin >> n;
    
  vector<int> a(n);
  f(i,n) cin >> a[i];
  
  cout << get(a,29);  
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}