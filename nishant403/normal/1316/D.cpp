#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e3+10;
pii dat[N][N];
pii nn = {-2,-2};
char dir[N][N];
int n;

int aa[] = {1,-1,0,0};
int bb[] = {0,0,1,-1};
char cc[] = {'U','D','L','R'};
char dd[] = {'D','U','R','L'};
//4 means blocked

bool valid(int i,int j)
{
    return (i>=0 && j>=0 && i<n && j<n && dir[i][j] == 'N');
}

bool valid2(int i,int j)
{
    return (i>=0 && j>=0 && i<n && j<n && dat[i][j] == nn);
}

void bfs(int i,int j)
{
    queue<pii> q;
    q.push({i,j});
 
    dir[i][j] = 'X';
    
    while(!q.empty())
    {
        auto x = q.front();
        q.pop();
        
        f(k,4) 
            if(valid(x.F+aa[k],x.S+bb[k]))
        {
            auto v = dat[x.F+aa[k]][x.S+bb[k]];
            
            if(v.F == i && v.S == j)
            {
                dir[x.F+aa[k]][x.S+bb[k]] = cc[k];
                q.push({x.F+aa[k],x.S+bb[k]});
            }
        }
            
    }
}

void solve()
{
   cin >> n;
    
   f(i,n) f(j,n) cin >> dat[i][j].F >> dat[i][j].S;
   f(i,n) f(j,n) dat[i][j].F--,dat[i][j].S--;
    
   f(i,n) f(j,n) dir[i][j] = 'N';
   f(i,n) f(j,n) if(dat[i][j].F == i && dat[i][j].S == j) bfs(i,j);
       
   f(i,n) f(j,n) if(dat[i][j] == nn)
       f(k,4) if(valid2(i+aa[k],j+bb[k])) dir[i][j] = dd[k];
   
   int flag = 1;
       
   f(i,n) f(j,n) if(dir[i][j] == 'N') flag = 0;
       
   if(flag == 0) cout << "INVALID\n";
   else
   {
       
   cout << "VALID\n";   
       
   f(i,n)
   {
       f(j,n) cout << dir[i][j];
       cout << '\n';
   }
       
   }
    
}
    

signed main()
{
    fast;
    solve();
}