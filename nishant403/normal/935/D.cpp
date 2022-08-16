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

const int M = 1e9+7;

int pw(int a,int b)
{
  int res = 1;
   
  a%=M;
  b%=(M-1);
    
  while(b)
  {
      if(b&1) res=(res*a)%M;
      a=(a*a)%M;
      b>>=1;
  }
    
  return res;
}

const int N = 1e5+10;
int a[N];
int b[N];
int n,m;

int go(int id)
{
    if(id == n) return 0;
    
    if(a[id] != 0 && b[id] != 0)
    {
        if(a[id] > b[id]) return 1;
        if(a[id] < b[id]) return 0;
        return go(id+1);
    }
    
   if(a[id] == 0 && b[id] != 0)
   {
       int res = ((m - b[id]) + go(id+1))%M;
       res = (res*pw(m,M-2))%M;
       return res;
   }
    
   if(a[id] !=0 && b[id] == 0)
   {
       int res = ((a[id]-1) + go(id+1))%M;
       res = (res*pw(m,M-2))%M;
       return res;
   }
    
   if(a[id] == 0 && b[id] == 0)
   {
       int res = (m*(m-1))/2;
       res += (m*go(id+1))%M;
       res = (res*pw(m,M-2))%M;
       res = (res*pw(m,M-2))%M;
       
       return res;
   }
    
    return 0;
}

void solve()
{
   cin >> n >> m;
    
   f(i,n) cin >> a[i];
   f(i,n) cin >> b[i];
    
   cout << go(0) << '\n';    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}