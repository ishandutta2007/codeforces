#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;
int cnt[N][N][4];
int cf[N][N];

int best[N][N];

bool match(int r1, int c1, int r2, int c2, int col){
  return (cnt[r2][c2][col]-cnt[r1-1][c2][col]-cnt[r2][c1-1][col]+cnt[r1-1][c1-1][col] == (r2-r1+1)*(c2-c1+1));
}

int lg[N];

int hh[N][N][12][12];

int qry(int r1, int c1, int r2, int c2){
  if(r1 > r2 || c1 > c2) return 0;
  int s1 = r2 - r1 + 1;
  int s2 = c2 - c1 + 1;
  int p = lg[s1];
  int q = lg[s2];
  return max({hh[r1][c1][p][q],hh[r2-(1<<p)+1][c1][p][q],hh[r1][c2-(1<<q)+1][p][q],hh[r2-(1<<p)+1][c2-(1<<q)+1][p][q]});
}

int main(){
  fastIO;
  int n, m, qq;
  cin >> n >> m >> qq;
  int pw = 0;
  for(int i = 1 ;i  < N ;i ++ ){
    while((1 << (pw + 1)) <= i)
      pw ++ ;
    lg[i]=pw;
  }
  char p;
  for(int i = 1 ; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> p;
      if(p == 'R') cf[i][j]=0;
      else if(p == 'G') cf[i][j]=1;
      else if(p == 'Y') cf[i][j]=2;
      else cf[i][j]=3;
      cnt[i][j][cf[i][j]]++;
      for(int t = 0 ; t < 4; t ++ ){
        cnt[i][j][t] += cnt[i-1][j][t] + cnt[i][j-1][t] - cnt[i-1][j-1][t];
      }
    }
  }
  int nl;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m; j ++ ){
      if(cf[i][j] == 0 && cf[i][j+1] == 1 && cf[i+1][j] == 2 && cf[i+1][j+1]==3){
        best[i][j]=1;
        int l = 1;
        for(int f = 11 ; f >= 0; f -- ){
          nl = l + (1 << f);

          if(i - nl + 1 >= 1 && i + nl <= n && j - nl + 1 >= 1 && j + nl <= m){
            if(match(i - nl + 1, j - nl + 1, i, j, 0) && match(i+1,j+1,i+nl,j+nl,3) && match(i-nl+1,j+1,i,j+nl,1) && match(i+1,j-nl+1,i+nl,j,2)){
              l = nl;
            }
          }
        }
        best[i][j]=l;
      }
    }
  }
  for(int i = 1 ;i <= n; i ++ ){
    for(int j = 1 ; j <= m; j ++ ){
      hh[i][j][0][0] = best[i][j];
    }
  }
  for(int p = 1 ; p < 12; p ++ ){
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j <= m ; j ++ ){
        if(i + (1 << p) - 1 <= n)hh[i][j][p][0]=max(hh[i][j][p-1][0],hh[i+(1<<(p-1))][j][p-1][0]);
        if(j + (1 << p) - 1 <= m)hh[i][j][0][p]=max(hh[i][j][0][p-1],hh[i][j+(1<<(p-1))][0][p-1]);
      }
    }
  }
  for(int p = 1; p < 12; p ++ ){
    for(int q = 1; q < 12; q ++ ){
      for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
          if(i + (1 << p) - 1 <= n && j + (1 << q) - 1 <= m){
            hh[i][j][p][q] = max({hh[i][j][p-1][q-1],hh[i+(1<<(p-1))][j][p-1][q-1],hh[i][j+(1<<(q-1))][p-1][q-1],hh[i+(1<<(p-1))][j+(1<<(q-1))][p-1][q-1]});
          }    
        }
      }
    }
  }
  int r1, c1, r2, c2;
  for(int i = 0 ;i < qq; i ++ ){
    cin >> r1 >> c1 >> r2 >> c2;
    int lf = 0,rf = min(n,m) + 9;
    int md;
    while(lf + 1 < rf){
      md = (lf + rf) / 2;
      if(qry(r1+(md-1),c1+(md-1),r2-md,c2-md) >= md)
        lf = md;
      else
        rf = md;
    }
    cout << 4*lf*lf << "\n";
  }
  return 0;
}