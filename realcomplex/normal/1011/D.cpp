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

int ask(int x){
  cout << x << endl;
  fflush(stdout);
  int y;
  cin >> y;
  if(y == 0){
    exit(0);
  }
  return y;
}

int main(){
  int m, n;
  cin >> m >> n;
  int p[n];
  int l;
  for(int i = 0;i < n;i ++ ){
    l = ask(1);
    if(l == 1)
      p[i] = 1;
    else
      p[i] = 0;
  }
  int cnt = 0;
  int lf = 1, rf = m, md;
  while(lf < rf){
    md = (lf + rf)/2;
    l = ask(md);
    if(p[cnt] == 0){
      l = -l;
    }
    if(l == 1)
      lf = md + 1;
    else
      rf = md;
    cnt ++ ;
    cnt %= n;
  }
  ask(lf);
  return 0;
}