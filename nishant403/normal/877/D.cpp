#include <bits/stdc++.h>
using namespace std;
   
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int inf = 1e7;

signed main()
{
    fast;
    
    int n,m,k;
    cin >> n >> m >> k;
    
    
    string grid[n];
    f(i,n) cin >> grid[i];
    f(i,n) f(j,m) if(grid[i][j] =='#') grid[i][j] ='@';

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    
    
    queue<pii> q;
    q.push({x1,y1});
    
    int dis[n][m];
    f(i,n) f(j,m) dis[i][j] = inf;
    
    set<int> row[n];
    set<int> col[m];
    
    f(i,n) f(j,m) row[i].insert(j);
    f(i,n) f(j,m) col[j].insert(i);
    
    row[x1].erase(y1);
    col[y1].erase(x1);
    dis[x1][y1] = 0;
    
    while(!q.empty())
    {
        auto x = q.front(); q.pop();
        
        int dd = dis[x.F][x.S] + 1;
       
        while(1)
        {
            if(row[x.F].empty()) break;
            
            auto v = row[x.F].upper_bound(x.S);
            
            if(v == row[x.F].begin()) break;
            
            --v;
            
            int xx = (*v);
            
            if(abs(x.S-xx) > k) break;
            
            if(grid[x.F][xx] == '@') break;
            
            dis[x.F][xx] = dd;
            
            q.push({x.F,xx});
            
            row[x.F].erase(xx);
            col[xx].erase(x.F);
        }
        
        while(1)
        {
            if(row[x.F].empty()) break;
            
            auto v = row[x.F].upper_bound(x.S);
            
            if(v == row[x.F].end()) break;
            
            int xx = (*v);
           
            if(abs(x.S-xx) > k) break;
           
            if(grid[x.F][xx] == '@') break;
           
            dis[x.F][xx] = dd;
            
            q.push({x.F,xx});
            
            row[x.F].erase(xx);
            col[xx].erase(x.F);
        } 
        
        while(1)
        {
            if(col[x.S].empty()) break;
            
            auto v = col[x.S].upper_bound(x.F);
            
            if(v == col[x.S].begin()) break;
            
            --v;
            
            int xx = (*v);
            
            if(abs(x.F-xx) > k) break;
            
            if(grid[xx][x.S] == '@') break;
           
            dis[xx][x.S] = dd;
            
            q.push({xx,x.S});
            
            row[xx].erase(x.S);
            col[x.S].erase(xx);
        }
        
        while(1)
        {
            if(col[x.S].empty()) break;
            
            auto v = col[x.S].upper_bound(x.F);
            
            if(v == col[x.S].end()) break;
            
            int xx = (*v);
            
            if(abs(x.F-xx) > k) break;
            
            if(grid[xx][x.S] == '@') break;
          
            dis[xx][x.S] = dd;
            
            q.push({xx,x.S});
            
            row[xx].erase(x.S);
            col[x.S].erase(xx);
        }
        
    }
    
    
    if(dis[x2][y2] == inf) cout << -1;
    else cout << dis[x2][y2];
}