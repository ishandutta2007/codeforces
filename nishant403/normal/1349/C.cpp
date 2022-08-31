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

const int N = 1e3 + 10;

bool col[N][N];
bool t1[N][N];
int take[N][N];
string s;

signed main()
{
    fast;
    
    int n,m,t;
    cin >> n >> m >> t;
    
    f(i,n)
    {
        cin >> s;
        f(j,m) col[i][j] = (s[j] - '0');
    }
    
    f(i,n) f(j,m)
    {
        if(i > 0 && col[i-1][j] == col[i][j]) t1[i][j] = 1;
        else if(i < n-1 && col[i][j] == col[i+1][j]) t1[i][j] = 1;
        else if(j > 0 && col[i][j] == col[i][j-1]) t1[i][j] = 1;
        else if(j < m-1 && col[i][j] == col[i][j+1]) t1[i][j] = 1;
    }
    
    //find take values 
    f(i,n) f(j,m) take[i][j] = (1e18 + 10);
    
    //first black turn of black
    f(i,n) f(j,m) if(t1[i][j] == 1) take[i][j] = 0;
    
    deque<pii> dq;
    
    f(i,n) f(j,m) if(take[i][j] == 0) dq.pb({i,j});
    
    while(!dq.empty())
    {
    auto v = dq.front();
    dq.pop_front();
        
    if(v.F > 0 && t1[v.F-1][v.S] == 0)
    {
        if(take[v.F-1][v.S] > take[v.F][v.S] + 1)
        {
            take[v.F-1][v.S] = take[v.F][v.S] + 1;
            dq.push_back({v.F-1,v.S});
        }
    }
        
    if(v.S > 0 && t1[v.F][v.S-1] == 0)
    {
        if(take[v.F][v.S-1] > take[v.F][v.S] + 1)
        {
            take[v.F][v.S-1] = take[v.F][v.S] + 1;
            dq.push_back({v.F,v.S-1});
        }
    }
        
     if(v.F < n-1 && t1[v.F+1][v.S] == 0)
    {
        if(take[v.F+1][v.S] > take[v.F][v.S] + 1)
        {
            take[v.F+1][v.S] = take[v.F][v.S] + 1;
            dq.push_back({v.F+1,v.S});
        }
    }
        
      if(v.S < m-1 && t1[v.F][v.S+1] == 0)
    {
        if(take[v.F][v.S+1] > take[v.F][v.S] + 1)
        {
            take[v.F][v.S+1] = take[v.F][v.S] + 1;
            dq.push_back({v.F,v.S+1});
        }
    }  
        
    }
    
    int i,j,p;
    
    while(t--)
    {
        cin >> i >> j >> p;
        
        i--; j--;
        
        if(t1[i][j] == 1)
        {
            p%=2;
            cout << (col[i][j]^p) << '\n';
        }
        else if(take[i][j] >= p) cout << col[i][j] << '\n';
        else 
        {
            p-=take[i][j]; p%=2;
            cout << (col[i][j]^p) << '\n';
        }
    }
}