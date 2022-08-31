#include <bits/stdc++.h>
using namespace std;
  
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 5004;
const int inf = 1e9;
int dp[N][N];
int n,m;
string a,b;

int go(int i,int j)
{
    if(i < 0 || j < 0) return 0;
    
    int & res = dp[i][j];
    
    if(res != -inf) return res;
    
    res = 0;
    
    if(a[i] == b[j]) res = 2 + go(i-1,j-1);
    else res = max(go(i-1,j),go(i,j-1)) - 1;
    
    if(res < 0) res = 0;
    
    return res;
}

signed main()
{
    fast;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) dp[i][j] = -inf;
        
    cin >> n >> m >> a >> b;
    
    
    int res = 0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) res = max(res,go(i,j));
    
    cout << res;
}