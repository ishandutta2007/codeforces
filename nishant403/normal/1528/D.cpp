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

const int N = 600 + 10;
const int inf = 1e18;

int dis[N][N];
int dd[N];
int vis[N];
int n,m;

void solve()
{
    cin >> n >> m;
    
    int x,y,z;
    
    f(i,n) f(j,n)
        dis[i][j] = inf;
        
    f(i,m)
    {
        cin >> x >> y >> z;
        dis[x][y] = min(dis[x][y],z);
    }
    
    f(i,n) 
    {
        f(j,n) dd[j] = dis[i][j];
        
        f(j,n) vis[j] = 0;
        
        f(j,n)
        {
            int v = -1;
            
            f(k,n)
                 if(vis[k] == 0)
            {
                if(v == -1) v = k;
                else if(dd[k] < dd[v]) v = k;
            }
            
            vis[v] = 1;
            
            dd[(v+1)%n] = min(dd[(v+1)%n] , dd[v] + 1);
            
            int tmp = dd[v] % n;
            
            //update all distances using vertex v 
            f(k,n)
            {
                dd[tmp] = min(dd[tmp], dd[v] + dis[v][k]);
                tmp++;
                if(tmp == n) tmp = 0;
            }
        }
        
        dd[i] = 0;
        f(j,n) cout << dd[j] << ' ';
        cout << '\n';
    }
}

signed main()
{
    fast;
    solve();
}