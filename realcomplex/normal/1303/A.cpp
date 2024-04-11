#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main(){ 
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ ){
    string t;
    cin >> t;
    int low = -1, high = -1;
    for(int j = 0 ; j < t.size(); j ++ ){
      if(t[j] == '1'){
        high = j;
        if(low == -1) low = j;
      }
    }
    int res = 0;
    for(int j = 0 ; j < t.size(); j ++ ){
      if(t[j] == '0' && j >= low && j <= high)
        res ++ ;
    }
    cout << res << "\n";
  }
  return 0;
}