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
  int testc;
  cin >> testc;
  for(int i = 0 ; i < testc; i ++ ){
    ll a, b;
    cin >> a >> b;
    ll x = 10;
    ll res = 0;
    for(int j = 0 ; j < 12; j ++ ){
      if(x-1 <= b){
        res += a;
      }
      x *= 10;
    }
    cout << res << "\n";
  }
  return 0;
}