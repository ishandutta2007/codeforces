#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5010;
string sh[N];
bool dp[N][N];

int main(){
  fastIO;
  string t;
  cin >> t;
  int n = t.size();
  int k = int(floor(log2(n))); // uhhhh
  int rem = n - ((1 << k) - 1);
  for(int i = 0 ; i <= n; i ++ ){
    sh[i] = "#";
  }
  sh[0] = "";
  dp[0][0]=true;
  int id;
  for(int len = 0; len < rem; len ++ ){
    char low = '#';
    vector<pii> cur;
    for(int j = 0 ; j < (1 << k); j ++ ){
      id = len + j;
      if(dp[id][j]){
        for(int g = 0 ;g < k ; g ++ ){
          if((j & (1 << g)) == 0){
            dp[id + (1 << g)][(j ^ (1 << g))] = true;
          }
        }
        if(low == '#'){
          low = t[id];
          cur.push_back(mp(id + 1, j));
        }
        else if(low > t[id]){
          low = t[id];
          cur.clear();
          cur.push_back(mp(id + 1, j));
        }
        else if(low == t[id]){
          cur.push_back(mp(id + 1, j));
        }
      }
    }
    sh[len + 1] = sh[len] + low;
    for(auto x : cur)
      dp[x.fi][x.se] = true;
  }
  cout << sh[rem] << "\n";
  return 0;
}