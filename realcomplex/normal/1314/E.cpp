#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2025;
const int M = 65;
const int MOD = 998244353;

int dp2[N][M]; // [sum][len][last] easy MLE
int dp1[N][N];

int n, k;

void add(int &a, int b){
  a += b;
  if(a >= MOD)
    a -= MOD;
}

void solve1(){
  for(int i = 0 ; i <= n; i ++ )
    dp1[0][i]=1;
  int ans = 0;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      if(i >= j){
        add(dp1[i][j],dp1[i-j][j]);
        add(ans, dp1[i][j]);
      }    
      add(dp1[i][j],dp1[i][j-1]);
    }
  }
  cout << ans << "\n";
}

void solve2(){
  dp2[0][0]=1;
  int ans = 0;
  for(int x = n; x >= 1; x -- ){
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j < M ; j ++ ){
        if(i >= j * x){
          add(dp2[i][j],dp2[i-j*x][j - 1]);
          add(ans,dp2[i-j*x][j-1]);
        }
      }
    }
  }
  cout << ans << "\n";
}

bool can(vector<int> t){
  if(t.size() > n)
    return false;
  for(int op = 0; op < k - 2 ; op ++ ){
    vector<int> nx;
    reverse(t.begin(), t.end());
    for(int i = 0 ; i < t.size();i ++ ){
      for(int j = 0; j < t[i]; j ++ )
        nx.push_back(i + 1);
    }
    t = nx;
    if(t.size() > n)
      return false;
  }
  int low = 1;
  int sig = 0;
  for(int i = t.size() - 1; i >= 0 ; i -- ){
    sig += t[i] * low;
    low ++ ;
  }
  if(sig > n) 
    return false;
  return true;
}

int res = 0;

void brute(vector<int> t){
  if(t.empty()){
    for(int i = 1; i <= n; i ++ ){
      t.push_back(i);
      if(!can(t))
        return;
      brute(t);
      t.pop_back();
    }
    return;
  }
  res ++ ;
  for(int i = t.back(); i <= n; i ++ ){
    t.push_back(i);
    if(!can(t))
      return;
    brute(t);
    t.pop_back();
  }
}

int main(){
  fastIO;
  cin >> n >> k;
  if(k == 1) solve1();
  else if(k == 2){
    solve2();
  }
  else{
    brute({});
    cout << res << "\n";
  }
  return 0;
}