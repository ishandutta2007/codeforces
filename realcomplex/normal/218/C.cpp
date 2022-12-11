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

bool xi[1005], yi[1005];

int p[2005];

const int N = 1001;

void init(){
  for(int i = 0;i < 2002;i ++ ){
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
  int n;
  cin >> n;
  int x, y;
  int el = 0;
  for(int i = 0;i < n;i ++ ){
    cin >> x >> y;
    el -= merge(x, y + N);
    if(xi[x] == false)
      el++, xi[x] = true;
    if(yi[y] == false)
      el++, yi[y] = true;
  }
  cout << el - 1;
  return 0;
}