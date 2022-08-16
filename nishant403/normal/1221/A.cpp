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
  int n;
    cin >> n;
    
  map<int,int> mp;
   
  mp[1] =  0;
    int temp = 1;
    
    for(int i=1;i<=29;i++)
    {
     temp=temp*2;
     mp[temp] = i;      
    }
  
    int x;
    vi a(30,0);
    
    f(i,n)
    {
     cin >> x;
     a[mp[x]]++;
    }
    
    for(int i=1;i<=11;i++)
    {
        a[i]+=a[i-1]/2;
    }
    
    if(a[11]) cout<<"YES\n";
    else cout <<"NO\n";
}

signed main()
{
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}