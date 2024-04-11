#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,p;
int s[11];
char a[1003][1003];
int dp[10][1003][1003];
queue<pair<int,int> >w[10];
char ch(int r){
    return char(r+int('0'));
}
bool bfs(int r,int c){
      queue<pair<int,int> >q=w[r];
      int cnt=0;
      bool ok=false;
      while (!q.empty() && dp[r][q.front().first][q.front().second]<c*s[r]){
            pair<int,int> v=q.front();
            int x=v.first;
            int y=v.second;
            q.pop();

            if (dp[r][x+1][y]>dp[r][x][y]+1 && a[x+1][y]=='.'){
                dp[r][x+1][y]=dp[r][x][y]+1;
                a[x+1][y]=ch(r);
                q.push({x+1,y});
                ok=true;
            }
            if (dp[r][x][y+1]>dp[r][x][y]+1 && a[x][y+1]=='.'){
                dp[r][x][y+1]=dp[r][x][y]+1;
                a[x][y+1]=ch(r);
                q.push({x,y+1});
                ok=true;
            }
            if (dp[r][x-1][y]>dp[r][x][y]+1 && a[x-1][y]=='.'){
                dp[r][x-1][y]=dp[r][x][y]+1;
                a[x-1][y]=ch(r);
                q.push({x-1,y});
                ok=true;
            }
            if (dp[r][x][y-1]>dp[r][x][y]+1 && a[x][y-1]=='.'){
                dp[r][x][y-1]=dp[r][x][y]+1;
                a[x][y-1]=ch(r);
                q.push({x,y-1});
                ok=true;
            }
      }
      w[r]=q;
      return ok;

}
int cnt[10];
int main()
{
   cin>>n>>m>>p;
   for (int i=1;i<=p;i++) cin>>s[i];

   for (int i=1;i<=n;i++){
       for (int j=1;j<=m;j++){
           cin>>a[i][j];
       }
   }

   for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int r=1;r<=p;r++) {
                 if (a[i][j]==ch(r)) {
                    dp[r][i][j]=0;
                    w[r].push({i,j});
                 }
                 else dp[r][i][j]=1000000001;
            }
        }
   }
   bool ok=true;
   int c=0;
   while (ok){
       c++;
       ok=false;
       for (int r=1;r<=p;r++) ok|=bfs(r,c);

   }
   for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (int(a[i][j])>int('0') && int(a[i][j])<=int('0')+p) cnt[a[i][j]-'0']++;
        }
   }
  for (int i=1;i<=p;i++) cout<<cnt[i]<<" ";
   return 0;
}
/*
4
GSGS
*/