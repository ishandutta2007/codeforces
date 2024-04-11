#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ ){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    y -= x;
    if(y % (a + b) == 0){
      cout << y/(a+b) << "\n";
    }
    else{
      cout << "-1\n";
    }
  }
  return 0;
}