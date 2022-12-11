#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ ){
    int a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    int dx = x - a + b;
    int dy = y - c + d;
    if(dx >= x1 && dx <= x2 && dy >= y1 && dy <= y2 && (x1 != x2 || (a+b)==0) && (y1 != y2 || (c+d==0))){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
  return 0;
}