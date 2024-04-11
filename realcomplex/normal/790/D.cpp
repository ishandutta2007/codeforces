#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
int nx[3][N];
int a[2][N];
map<ll,int>las;

int ans[N];

struct B{
  int value;
  int l0;
  int l1;
};

vector<B> ex[N];

void upd(int i, int j, int v){
  ans[max(i,j)] = max(ans[max(i,j)], v);
  ex[min(i,j)].push_back({v,i,j});
}

int n;
void ext(int i, int j, int vl){
  int p;
  if(i + 1 <= n){
    upd(i + 1, j, vl);
    p = nx[0][i];
    if(p != -1)
      upd(p, j, vl + 1);
  }
  if(j + 1 <= n){
    upd(i, j + 1, vl);
    p = nx[1][j];
    if(p != -1)
      upd(i, p, vl + 1);
  }
  if(i == j && i + 1 <= n){
    upd(i + 1,i + 1, vl);
    p = nx[2][i];
    if(p != -1)
      upd(p, p, vl + 1);
  }
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 0 ; i < 3 ; i ++ ){
    for(int j = 0 ; j <= n; j ++ )
      nx[i][j] = -1;
  }
  for(int i = 0 ; i < 2; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      cin >> a[i][j];
    }
  }
  ll sum = 0;
  for(int i = 0 ; i < 3; i ++ ){
    las.clear();
    las[0] = 0;
    sum = 0;
    for(int j = 1; j <= n; j ++ ){
      if(i == 0 || i == 2) sum += a[0][j];
      if(i == 1 || i == 2) sum += a[1][j];
      if(las.count(sum)){
        nx[i][las[sum]] = j;
      }
      las[sum] = j;
    }
  }
  int low;
  for(int i = 0 ; i <= n; i ++ ){
    ext(i, i, ans[i]);
    low = (int)1e9;
    for(auto p : ex[i]){
      if(p.l0 == i && ans[i] + 1 == p.value) low = min(low, p.l1);
    }
    if(low != (int)1e9)ext(i, low, ans[i] + 1);
    low = (int)1e9;
    for(auto p : ex[i]){
      if(p.l1 == i && ans[i] + 1 == p.value) low = min(low, p.l0);
    }
    if(low != (int)1e9)ext(low, i, ans[i] + 1);
  }
  cout << ans[n] << "\n";
  return 0;
}