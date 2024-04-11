#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

const int Inf = (int)2e9 + 9;
const int N = 21;
int dp[1 << N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int s[n];
  for(int i = 0;i < n;i ++ )
    cin >> s[i];
  sort(s, s + n);
  reverse(s, s + n);
  int m;
  cin >> m;
  char op[m];
  int team[m];
  for(int i = 0;i < m;i ++ ){
    cin >> op[i] >> team[i];
  }
  int move;
  for(int i = 1;i < (1<<m);i ++ ){
    move = m-ones(i); 
    if(team[move] == 1)
      dp[i] = -Inf;
    else
      dp[i] = Inf;
    for(int j = 0;j < m;j ++ ){
      if((i & (1 << j))){
        if(team[move] == 1){
          if(op[move] == 'p') dp[i] = max(dp[i], dp[(i^(1<<j))] + s[j]);
          else dp[i] = max(dp[i], dp[(i^(1<<j))]);
        }
        else{
          if(op[move] == 'p') dp[i] = min(dp[i], dp[(i^(1<<j))] - s[j]);
          else dp[i] = min(dp[i], dp[(i^(1<<j))]);
        }
      }
    }
  }
  cout << dp[(1 << m) - 1];
  return 0;
}