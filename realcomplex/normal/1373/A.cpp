#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    int a, b, c;
    cin >> a >> b >> c;
    if(a >= c){
      cout << "-1 ";
    }
    else{
      cout << 1 << " ";
    }
    if(a * 1ll * b <= c){
      cout << "-1";
    }
    else{
      cout << b;
    }
    cout << "\n";
  }
  return 0;
}