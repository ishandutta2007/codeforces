#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = 7005;

int dp[2][N]; 
int d[2][N];

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<int> moves[2];
  queue<pii> state;
  int k, x;
  for(int i = 0;i < 2;i ++ ){
    cin >> k;
    for(int j = 0;j < k;j ++ ){
      cin >> x;
      moves[i].push_back(x);
    }
    for(int v = 1; v < n; v ++ ){
      d[i][v] = k;
      dp[i][v] = 0;
    }
    dp[i][0] = 1;
    state.push(mp(i, 0));
  }
  int pos, move;
  int nex_pos;
  while(!state.empty()){
    pos = state.front().se;
    move = state.front().fi;
    state.pop();
    for(auto x : moves[1-move]){
      nex_pos = (pos - x + n) % n;
      if(dp[1 - move][nex_pos] > 0)
        continue;
      if(dp[move][pos] == 2){
        d[1 - move][nex_pos] -- ;
        if(d[1 - move][nex_pos] == 0){
          dp[1 - move][nex_pos] = 1;
          state.push(mp(1 - move, nex_pos));
        }
      }
      else{
        dp[1 - move][nex_pos] = 2;
        state.push(mp(1 - move, nex_pos));
      }
    }
  }
  for(int j = 0; j < 2;j ++ ){
    for(int i = 1;i < n;i ++ ){
      if(dp[j][i] == 0){
        cout << "Loop ";
      }
      else if(dp[j][i] == 1){
        cout << "Lose ";
      }
      else{
        cout << "Win ";
      }
    }
    cout << "\n";
  }
  return 0;
}