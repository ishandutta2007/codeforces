#include <bits/stdc++.h>

using namespace std;

const int N = 110;

string a, b;
string virus;
int n, m, p;
int f[N];
int g[N];
int dp[N][N][N];
int jump[N][N + N];
pair < pair < int, int >, int > nadeko[N][N][N];

bool maximize(int &u, int v){
  if(u < v){
    u = v;
    return true;
  }
  return false;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  cin >> a >> b >> virus;
  p = virus.size();
  for(int i = 1; i < virus.size(); ++i){
    int j = f[i - 1];
    while(true){
      if(virus[i] == virus[j]){
        f[i] = j + 1;
        break;
      }
      else{
        if(j == 0){
          break;
        }
        j = f[j - 1];
      }
    }
  }
  for(int i = 0; i <= p; ++i){
    string current;
    for(int j = 0; j < i; ++j){
      current += virus[j];
    }
    for(char c = 'A'; c <= 'Z'; ++c){
      string now = current + c;
      memset(g, 0, sizeof g);
      g[0] = (now[0] == virus[0]);
      for(int i = 1; i < now.size(); ++i){
        int j = g[i - 1];
        if(j == virus.size()){
          j = f[j];
        }
        while(true){
          if(now[i] == virus[j]){
            g[i] = j + 1;
            break;
          }
          else{
            if(j == 0){
              break;
            }
            j = f[j - 1];
          }
        }
      }
      jump[i][c] = g[now.size() - 1];
    }
  }
  memset(dp, -1, sizeof dp);
  a = "1" + a;
  b = "2" + b;
  n = a.size();
  m = b.size();
  dp[0][0][0] = 0;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < p; ++k){
        if(dp[i][j][k] == -1){
          continue;
        }
        if(maximize(dp[i + 1][j][k], dp[i][j][k])){
          nadeko[i + 1][j][k] = make_pair(make_pair(i, j), k);
        }
        if(maximize(dp[i][j + 1][k], dp[i][j][k])){
          nadeko[i][j + 1][k] = make_pair(make_pair(i, j), k);
        }
        if(i < n - 1 && j < m - 1 && a[i + 1] == b[j + 1] && jump[k][a[i + 1]] < p){
          if(maximize(dp[i + 1][j + 1][jump[k][a[i + 1]]], dp[i][j][k] + 1)){
            nadeko[i + 1][j + 1][jump[k][a[i + 1]]] = make_pair(make_pair(i, j), k);
          }
        }
      }
    }
  }
  int u, v, t;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < p; ++k){
        if(maximize(ans, dp[i][j][k])){
          u = i;
          v = j;
          t = k;
        }
      }
    }
  }
  if(ans == 0){
    cout << 0;
    return 0;
  }
  string rev;
  while(true){
    int i = nadeko[u][v][t].first.first;
    int j = nadeko[u][v][t].first.second;
    int k = nadeko[u][v][t].second;

    if(dp[i][j][k] < dp[u][v][t]){
      rev += a[u];
    }
    if(u == 0 || v == 0){

      break;
    }
    u = i;
    v = j;
    t = k;
  }
  reverse(rev.begin(), rev.end());
  cout << rev;
  return 0;
}