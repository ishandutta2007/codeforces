#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N], b[N], x[N], y[N];

int main(){
  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  
  int ansx = -1, ansy;
  
  for(int p= 1; p <= n; ++p) {
    multiset < pair < int, int > > points;
    for(int i = 1; i <= n; ++i) if(i != p) points.emplace(x[i], y[i]);
    
    int Tx = a[1] + x[p], Ty = b[1] + y[p];
    
    bool able = true;;
    
    for(int i = 2; i <= n; ++i) {
      if(!points.count(make_pair(Tx - a[i], Ty - b[i]))) {
        able = false;
        break;
      }
      else{
        points.erase(points.lower_bound(make_pair(Tx - a[i], Ty - b[i])));
      }
    }
    
    if(able) {
      cout << Tx << " " << Ty << endl;
      return 0;
    }
  }
  
  return 0;
}