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
#define ones(a) __builtin_popcount(a);
const int N = 200019;

int p[N + N + 1];
void init(){
  for(int i = 0;i < N + N + 1;i ++ ){
    p[i] = i;
  }
}

int fin(int a){
  if(a == p[a])
    return a;
  return p[a] = fin(p[a]);
}

bool merge(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b)
    return false;
  p[b] = a;
  return true;
}

int main(){
  fastIO;
  init();
  int n, m, q;
  cin >> n >> m >> q;
  int el = n + m - 1;
  int x, y;
  for(int i = 0;i < q;i ++ ){
    cin >> x >> y;
    el -= merge(x, y + N);
  }
  cout << max(0, el);
  return 0;
}