#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    int n, x;
    cin >> n >> x;
    vector<int> f(n + 1);
    char z;
    int B = 0;
    int rhs;
    int c;
    for(int i = 1; i <= n; i ++ ){
      cin >> z;
      if(z == '1')
        f[i] = -1;
      else
        f[i] = +1;
      B += f[i];
    }

    int sol = 0;
    c = 0;
    for(int i = 0 ; i < n;  i ++ ){
      c += f[i];
      rhs = x - c;
      if(B == 0){
        if(rhs == 0){
          sol = -1;
          break;
        }
      }
      else{
        if(rhs % B == 0 && rhs / B >= 0){
          sol ++ ;
        }
      }
    }
    cout << sol << "\n";
  }
  return 0;
}