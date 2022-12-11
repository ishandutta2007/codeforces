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
  for(int i = 0 ;i  < tc; i ++ ){
    int n;
    cin >> n;
    if(n == 1)
      cout << "-1\n";
    else{
      for(int i = 0; i < n - 1; i ++ )
        cout << 5;
      cout << 4;
      cout << "\n";
    }
  }
  return 0;
}