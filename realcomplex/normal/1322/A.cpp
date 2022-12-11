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
  int n;
  cin >> n;
  string t;
  cin >> t;
  int cnt = 0;
  int ans = 0;
  for(char x : t){
    if(x == '('){
      if(cnt == -1) ans ++ ;
      cnt ++ ;
    }
    else{
      cnt -- ;
    }
    if(cnt < 0)
      ans ++ ;
  }
  if(cnt != 0)
    cout << -1;
  else
    cout << ans;
  return 0;
}