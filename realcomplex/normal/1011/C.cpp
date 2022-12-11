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

void No(){
  cout << -1;
  exit(0);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  db ms;
  cin >> ms;
  db a[n], b[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
    if(a[i] == 1.0)
      No();
  }
  for(int i = 0;i < n;i ++ ){
    cin >> b[i];
    if(b[i] == 1.0)
      No();
  }
  db req = 0.0;
  db l = 0.0, r = 1e9 + 1.0;
  db dd;
  db tot;
  db fuel;
  int ap, bp;
  db rq;
  for(int prec = 0; prec < 211; prec ++ ){
    req = 0.0;
    dd = (l + r)/2;
    fuel = dd;
    tot = dd + ms;
    ap = 0;
    bp = 1;
    for(int i = 0;i < n;i ++ ){
      rq = tot / a[ap];
      tot -= rq;
      fuel -= rq;
      rq = tot / b[bp];
      tot -= rq;
      fuel -= rq;
      ap ++ ;
      bp ++ ;
      ap %= n;
      bp %= n;
    }
    if(tot < ms)
      l = dd;
    else
      r = dd;
  }
  cout << fixed << setprecision(7) << l << "\n";
  return 0;
}