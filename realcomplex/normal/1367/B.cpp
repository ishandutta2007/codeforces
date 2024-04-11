#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    int n;
    cin >> n;
    int b1 = 0, b2 = 0;
    int x;
    for(int i = 0 ; i < n ; i ++ ){
      cin >> x;
      if(x % 2 == i % 2){
        continue;
      }
      else{
        if(i % 2 == 0) b1 ++ ;
        else b2 ++ ;
      }
    }
    if(b1 == b2)
      cout << b1 << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}