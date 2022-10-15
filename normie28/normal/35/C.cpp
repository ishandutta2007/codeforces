#include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"

 
 
  int dx[]={-1,1,0,0};
  int dy[]={0,0,1,-1};
 
  bool inrange(int x,int y,int n,int m)
  {
    if(x < 1 or x > n or y < 1 or  y > m)
    {
      return false;
    }
    return true;
  }
  int32_t main()
  {        
  
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
      IOS
      int n ,m ,k ;
      cin >> n >> m >> k;
      vector<vector<int>> visited(n+1,vector<int> (m+1,0)),dist(n+1,vector<int> (m+1,0));
      queue<pair<int,int>>q;
      for (int  i = 0 ; i < k ; i++)
      {
        int x ,y;
        cin >> x >> y;
        q.push({x,y});
        visited[x][y] = true ; 
      }
 
 
      while(!q.empty())
      {
        auto k = q.front();
        q.pop();
 
          for(int  i = 0; i < 4; i++)
          {
            int newx = k.first + dx[i];
            int newy = k.second + dy[i];
 
              if(!inrange(newx,newy,n,m) or visited[newx][newy])
              {
                continue;
              }
                dist[newx][newy] = dist [k.first] [k.second] + 1;
                visited [newx][newy] =1;
                q.push({newx,newy});
          }
      } 
 
        int ans = -1, x = 1, y =1;
 
 
      for (int  i = 1;i <= n; i++)
      {
          for(int j = 1; j <=m; j++)
          {
            if(dist[x][y]<dist[i][j])
            {
              x = i , y = j;
            }
          }
      }
 
      cout << x << " " << y;
      //time();
    return 0;
 
     }