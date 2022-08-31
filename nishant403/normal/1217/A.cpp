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
  int str,in,exp;
    cin >> str >> in >> exp;
    
    if(str + exp <= in) { cout<< "0\n"; return; }
    
    int great = str+exp;
    
    int l = str;
    int r = str + exp;
    int ans = r;
    
    while(l<=r)
    {
      int mid =(l+r)/2;
        
      int given = mid - str;
      int another = in + (exp - given);
        
      if( mid > another)
      {
        ans = min(ans,mid); r = mid -1;   
      }
        else l = mid + 1;
        
    }
        
    cout << (great-ans+1) <<"\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}