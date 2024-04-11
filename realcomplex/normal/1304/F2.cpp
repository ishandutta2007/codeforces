#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 52;
const int M = 20005;
int dp[N][M];

int tree[M * 4 + 512];
int lazy[M * 4 + 512];
int lim;

void push(int node, int cl, int cr){
  tree[node] += lazy[node];
  if(cl != cr){
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

void upd(int node, int cl, int cr, int tl, int tr, int v){
  push(node, cl, cr);
  if(cr < tl)
    return;
  if(cl > tr)
    return;
  if(cl >= tl && cr <= tr){
    lazy[node] = v;
    push(node, cl, cr);
    return;
  }
  int mid = (cl + cr) / 2;
  upd(node * 2, cl, mid, tl, tr, v);
  upd(node * 2 + 1, mid + 1, cr, tl, tr, v);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}


int pf[N][M];
int a[N][M];

int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> a[i][j];
      pf[i][j] = a[i][j] + pf[i][j-1];
    }
  }
  for(int j = 1; j <= m - k + 1; j ++ )
    dp[1][j] = pf[1][j + k - 1] - pf[1][j-1];
  int ad;
  int p;
  for(int i = 2; i <= n; i ++ ){
    for(int j = 0 ; j < 4 * M + 512; j ++ ){
      tree[j] = 0;
      lazy[j] = 0;
    }
    for(int j = 1; j <= m - k + 1; j ++ ){
      ad = pf[i][j+k-1]-pf[i][max(k,j-1)];
      upd(1, 1, m, j, j,dp[i-1][j]+ad);
    }
    dp[i][1]=tree[1]+pf[i][k];
    for(int j = 2; j <= m - k + 1; j ++ ){
      p = j - 1;
      upd(1, 1, m, max(1,p - k + 1), p, a[i][p]);
      p = j + k - 1;
      upd(1, 1, m, j, j + k - 1, -a[i][p]);
      dp[i][j]=tree[1]+pf[i][j+k-1]-pf[i][j-1];
    }
  }
  int res = 0;
  for(int i = 1; i <= m - k + 1; i ++ )
    res = max(res, dp[n][i]);
  cout << res << "\n";
  return 0;
}