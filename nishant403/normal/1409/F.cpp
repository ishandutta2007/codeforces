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

const int N = 210;
const int inf = 1e10;

vector<vi> cur(N,vi(N,0)) , nex(N, vi(N,0));
            
void solve()
{
   int n,k;
    cin >> n >> k;
    
   string s,t;
    cin >> s >> t;
    
    
   if(t[0] == t[1]) 
   {
      f(i,n) if(s[i] != t[0] && k > 0)
      {
          s[i] = t[0];
          k--;
      }
        
      int res = 0;
       
      f(i,n) if(s[i] == t[0]) res++;
      res = (res*(res-1))/2;    
      cout << res << '\n'; 
      return; 
   }
    
   f(i,205) f(j,205) cur[j][i] = -inf; 
   cur[k][0] = 0; 
    
   f(i,n)
   {
       f(j,205) f(l,205) nex[j][l] = -inf;
       
       f(j,k+1) f(l,n)
       {
           //do not change current char
           if(s[i] == t[0] && l > 0) nex[j][l] = max(nex[j][l],cur[j][l-1]);
           
           if(s[i] != t[1]) nex[j][l] = max(nex[j][l],cur[j][l]);
           else nex[j][l] = max(nex[j][l], cur[j][l] + l);
           
           //make it t[0]
           if(l > 0) nex[j][l] = max(nex[j][l],cur[j+1][l-1]);
           
           //make it t[1]
           nex[j][l] = max(nex[j][l],cur[j+1][l] + l);
       }
       
       swap(cur,nex);
   }
    
   int res = -inf;
    
   f(i,k+1) f(j,n) res = max(res,cur[i][j]);
    
   cout << res;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}