#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = 1009;
char conf[N][N];

int Left[N][N];
int Right[N][N];
int Up[N][N];
int Down[N][N];

int sLeft[N][N];
int sUp[N][N];

int sum[N][N];

struct Star{
  int xcor;
  int ycor;
  int depth;
};

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  for(int i = 1; i <= n;i ++ ){
    for(int j = 1;j <= m;j ++ ){
      cin >> conf[i][j];
      if(conf[i][j] == '*'){
        Left[i][j] = Left[i][j - 1] + 1;
        Up[i][j] = Up[i - 1][j] + 1;
      }
    }
  }
  int dd;
  for(int i = n;i >= 1;i -- ){
    for(int j = m;j >= 1; j -- ){
      if(conf[i][j] == '*'){
        Right[i][j] = Right[i][j + 1] + 1;
        Down[i][j] = Down[i + 1][j] + 1;
      }
    }
  }
  int ff;
  Star add;
  vector<Star> st;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1; j <= m;j ++ ){
      ff = min({Left[i][j], Right[i][j], Up[i][j], Down[i][j]});
      if(conf[i][j] == '.')
        continue;
      if(ff <= 1)
        continue;
      sum[i][j] ++ ;
      sUp[i - ff + 1][j] ++ ;
      sUp[i + ff][j] --;
      sLeft[i][j - ff + 1] ++ ;
      sLeft[i][j + ff] -- ;
      add.xcor = i;
      add.ycor = j;
      add.depth = ff-1;
      st.push_back(add);
    }
  }
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= m;j ++ ){
      sLeft[i][j] += sLeft[i][j - 1];
      sUp[i][j] += sUp[i - 1][j];
    }
  }
  int mx;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= m;j ++ ){
      mx = max({sLeft[i][j], sUp[i][j], sum[i][j]});
      if(mx == 0 and conf[i][j] == '*'){
        cout << -1;
        return 0;
      }
    }
  }
  cout << st.size() << "\n";
  for(auto x : st){
    cout << x.xcor << " " << x.ycor << " " << x.depth << "\n";
  }
  return 0;
}