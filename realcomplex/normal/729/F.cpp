#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = 4005;
const int K = 95;

bool vis[N][K][K][2];
int ans[N][K][K][2];
int pref[N];

int n;

int sumq(int lf, int rf){
  return pref[rf] - pref[lf - 1];
}

int solve(int l, int r, int k, int move){
  if(r - l + 1 < k)
    return 0;
  if(r - l + 1 == k)
    return sumq(l, r);
  if(vis[l][n-r-l+1][k][move])
    return ans[l][n-r-l+1][k][move];
  int rz;
  if(move == 0){ // Igor's move
    rz = max(sumq(l, l+k-1) - solve(l + k, r, k, !move), sumq(l, l + k) - solve(l + k + 1, r, k+1, !move));
  }
  else{ // Zhenya's move
    rz = max(sumq(r-k+1, r) - solve(l, r-k, k, !move) , sumq(r-k, r) - solve(l, r-k-1, k + 1, !move) );
  }
  vis[l][n-r-l+1][k][move] = true;
  ans[l][n-r-l+1][k][move] = rz;
  return rz;
}

int main(){
  fastIO;
  cin >> n;
  int x;
  for(int i = 1;i <= n;i ++ ){
    cin >> x;
    pref[i] = x;
    pref[i] += pref[i - 1];
  }
  cout << solve(1, n, 1, 0);
  return 0;
}