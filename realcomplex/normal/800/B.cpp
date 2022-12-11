#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1005;
ld x[N];
ld y[N];

ld pp(ld x0, ld y0, ld x1, ld y1){
  return sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));
}

ld area(ld x0, ld y0, ld x1, ld y1, ld x2, ld y2){  
  // ehhhh ill use heron
  ld A = pp(x0,y0,x1,y1);
  ld B = pp(x1,y1,x2,y2);
  ld C = pp(x2,y2,x0,y0);
  ld p = (A + B + C) / 2.0;
  return sqrt(p * (p - A) * (p - B) * (p - C));
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i < n; i ++ ){
    cin >> x[i] >> y[i];
  }
  ld ans = (ld)1e12;
  ld cur;
  for(int i = 0 ; i < n ; i ++ ){
    cur = area(x[i],y[i],x[(i+n-1)%n],y[(i+n-1)%n],x[(i+1)%n],y[(i+1)%n]);
    ans = min(ans,  cur / pp(x[(i+n-1)%n],y[(i+n-1)%n],x[(i+1)%n],y[(i+1)%n]));
  }
  cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}