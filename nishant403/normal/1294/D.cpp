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

const int N = 4e5+10;
int cnt[N];

void solve()
{
  int q,x;
  cin >> q >> x;
    
 int y;   
 int mex = 0; 
    
  f(i,q)
  {
      cin >> y;
      
      cnt[y%x]++;
      
      while(cnt[mex%x]>0) cnt[mex%x]--,mex++;
      
      cout << mex << '\n';
  }
    
    
}

signed main()
{
    fast;
    solve();
}