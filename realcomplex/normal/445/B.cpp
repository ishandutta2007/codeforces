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

const int N = 51;
int p[N];

void init(){
  for(int i = 0;i < N; i ++ ){
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
  init();
  fastIO;
  int n, m;
  cin >> n >> m;
  int a, b;
  ll ans = 1;
  for(int i = 0;i < m; i ++ ){
    cin >> a >> b;
    if(merge(a, b)){
      ans *= 2;
    }
  }
  cout << ans;
  return 0;
}