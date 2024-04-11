#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j <= m ; j ++ ){
        if(i == 1 && j == 1) cout << "W";
        else cout << "B";
      }
      cout << "\n";
    }
  }
  return 0;
}