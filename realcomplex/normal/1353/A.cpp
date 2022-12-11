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
  for(int t = 0; t < tc; t ++ ){
    ll n, m;
    cin >> n >> m;
    if(n == 1)
      cout << 0 << "\n";
    else if(n == 2){
      cout << m << "\n";
    }
    else{
      cout << 2 * m << "\n";
    }
  }
  return 0;
}