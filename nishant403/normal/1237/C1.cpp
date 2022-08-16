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

int get(pair<pii,pii> & a,pair<pii,pii> & b)
{
  int res = 0;
  int temp = 0;
    
  temp=(a.F.F-b.F.F);
  temp*=temp;
  res+=temp;
    
  temp=(a.F.S-b.F.S);
  temp*=temp;
  res+=temp;
    
  temp=(a.S.F-b.S.F);
  temp*=temp;
  res+=temp;
    
  return res;  
}

void solve()
{
  int n;
    cin >> n ;
    
  pair<pii,pii> pt[n];
    f(i,n) cin >> pt[i].F.F >> pt[i].F.S >> pt[i].S.F ;
    
    f(i,n) pt[i].S.S = 0;
    
    f(i,n)
    {  
        if(pt[i].S.S == 1) continue;
        
        pt[i].S.S = 1;
        
        int dd = 1e18;
        int id = -1;
        
        for(int j=0;j<n;j++)
        {
            if(pt[j].S.S == 1) continue;
            
            int v = get(pt[i],pt[j]);
            
            if(v < dd)
            {
               dd = v;
               id = j;
            }
            
        }
        
        cout << i+1 <<" "<<id+1 <<"\n";
        
        pt[id].S.S = 1;
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