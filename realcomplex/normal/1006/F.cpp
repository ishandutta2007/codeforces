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

const int N = 20;
ll vl[N][N];
map<ll, ll> cnt[N][N];

int part1, part2;
int n, m;
ll k;

void dfs1(int x, int y, ll val, int depth){
  val ^= vl[x][y];
  if(depth == part1){
    cnt[x][y][val] ++ ;
    return;
  } 
  depth ++ ;
  if(x + 1 < n)
    dfs1(x + 1, y, val, depth);
  if(y + 1 < m)
    dfs1(x, y + 1, val, depth);
}

ll ans = 0;

void dfs2(int x, int y, ll val, int depth){
  if(depth == part2){
    ans += cnt[x][y][val ^ k];
    return;
  }
  val ^= vl[x][y];
  depth ++ ;
  if(x > 0)
    dfs2(x - 1, y, val, depth);
  if(y > 0)
    dfs2(x, y - 1, val, depth);
}

int main(){
  fastIO;
  cin >> n >> m >> k;
  for(int i = 0;i < n; i++ ){
    for(int j = 0;j < m;j ++ ){
      cin >> vl[i][j];
    }
  }
  int hf = (n + m - 2);
  part1 = hf/2;
  part2 = hf - part1;
  dfs1(0, 0, 0ll, 0);
  dfs2(n-1,m-1,0ll,0);
  cout << ans;
  return 0;
}