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

const int N = 1e3 + 5;
double dp[N][N][2];
bool done[N][N][2];

double go(int w,int b,int turn)
{
    assert(w>=0 && b>=0);
    
    if(done[w][b][turn]) return dp[w][b][turn];
    done[w][b][turn] = 1;
    
    double & res = dp[w][b][turn];
    res = 0.000000;
    
    if(w == 0) 
    {
       if(turn == 1) return res = 1.000000;
       else return res;
    }
    
  if(turn == 0)
  {
    res = (double)w/(w+b);
    if(b>0) res += ((double)b/(w+b))*(1-go(w,b-1,turn^1));  
  }
  else if(turn == 1)
  {
    res = (double)w/(w+b);
    if(b>1) res += ((double)b/(w+b))*((double)(b-1)/(w+b-1))*(1-go(w,b-2,turn^1));
    if(w>0 && b>0) res += ((double)b/(w+b))*((double)w/(w+b-1))*(1-go(w-1,b-1,turn^1));
  }
    
  return res;
}

void solve()
{
    int w,b;
    cin >> w >> b;
    cout << fixed << setprecision(9) << go(w,b,0) << '\n';  
}

signed main()
{
    fast;
    solve();
}