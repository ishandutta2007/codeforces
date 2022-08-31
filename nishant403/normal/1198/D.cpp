#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

const int N = 51;
int dp[N][N][N][N];
string s[N];
int n;

int solve(int x1,int y1,int x2,int y2)
{
    if(x1 == x2 && y1 == y2)
    {
        return s[x1][y1] == '#';
    }
    
    int & res = dp[x1][y1][x2][y2];
    
    if(res != -1) return res;
    
    res = max(y2-y1+1,x2-x1+1);
    
    for(int i=x1;i<x2;i++)
    {
        res = min(res , solve(x1,y1,i,y2) + solve(i+1,y1,x2,y2) );
    }
   
    for(int j=y1;j<y2;j++)
    {
        res = min(res , solve(x1,y1,x2,j) + solve(x1,j+1,x2,y2));
    }
    
    return res;
}

void solve()
{
   cin >> n;
   f(i,n) cin >> s[i];
    
   memset(dp,-1,sizeof(dp));
   cout << solve(0,0,n-1,n-1);
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}