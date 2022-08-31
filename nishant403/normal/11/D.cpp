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
#define all(x) x.begin(),x.end()

const int N = 19;

int go[1<<N];
int cc[1<<N];
    
int dp[1<<N][N];
int g[N][N];

int n,m;
int res = 0;

void solve2()
{
    f(i,n) f(j,n)
        if(i < j && g[i][j] == 1)
            dp[(1LL<<i) | (1LL<<j)][j] = 1;
        
    f(i,(1<<n)) 
    {
        if(cc[i] < 3) continue;
        
        f(j,n) if((i>>j) & 1 && j != go[i])
        {
            int nmask = (i^(1<<j));

            f(k,n) if((i>>k) & 1)
            {
                if(g[k][j] == 1)
                {
                    dp[i][j] += dp[nmask][k];  
                }
            }

            if(g[j][go[i]]) res += dp[i][j];
        }
    }
}

void solve()
{
   cin >> n >> m;
    
   f(i,(1<<n)) 
   {
       go[i] = __builtin_ctz(i); 
       cc[i] = __builtin_popcount(i);
   }
    
   int u,v;
    
   f(i,m)
   {
       cin >> u >> v;
       u--,v--;
       g[u][v] = g[v][u] = 1;
   }
   
   solve2(); 
   
   res /= 2; 
   cout << res;
}

signed main()
{
    fast;
    solve();
}