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
  for(int t = 0 ;t < tc; t ++ ){
    int a, b;
    cin >> a >> b;
    if(a == b)
      cout << 0 << "\n";
    else{
      if(a > b){
        if(a % 2 == b % 2)
          cout << 1 << "\n";
        else 
          cout << 2 << "\n";
      }
      else{
        if(a % 2 != b % 2)
          cout << 1 << "\n";
        else
          cout << 2 << "\n";
      }
    }
  }
  return 0;
}