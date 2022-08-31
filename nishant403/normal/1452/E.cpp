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

int inter(pii a,pii b)
{
    if(a.S < b.F || b.S < a.F) return 0;
    return min(a.S,b.S) - max(a.F,b.F) + 1;
}

const int N = 2e3 + 10;
pii best[N];

signed main()
{
   fast;
 
   int n,m,k;
    cin >> n >> m >> k;
    
   pii a[m];
    f(i,m) cin >> a[i].F >> a[i].S;
    f(i,m) a[i].F--,a[i].S--;
    
   int res = 0;
    
   f(i,n-k+1) 
   {
       int temp1 = 0;
       f(j,m) temp1+=inter( {i,i+k-1} , a[j] );
       
       f(j,n) best[j] = {0,0};
       
       f(j,m)
       {
          if(a[j].F <= i) continue;
          if(a[j].S <= i + k - 1) continue;
           
          int cur_best = inter({i,i+k-1},a[j]);
          int len = a[j].S - a[j].F + 1;
          int mx_val = min(k,len);
          int start = a[j].F - k + 1 + cur_best;
          int mx_start = min(a[j].F,a[j].S-k+1);
          int mx_end = a[j].S - mx_val + 1;
          int end = a[j].S - cur_best;
           
          if(mx_val > cur_best && start <= mx_start && mx_start <= mx_end && mx_end <= end)
          {
              best[start].F++;
              best[start].S++;
              best[mx_start].S--;
              best[mx_end].S--;
              best[end].S++;
              best[end+1].F--;
          }
       }
       
       for(int j=0;j<n;j++)
       {
          if(j) best[j].F+=best[j-1].S + best[j-1].F;
          if(j) best[j].S+=best[j-1].S;
           res = max(res,temp1 + best[j].F);
       }
   }
    
   cout << res; 
}