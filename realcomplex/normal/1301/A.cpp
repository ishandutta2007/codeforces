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
  for(int i = 0 ; i < tc; i ++ ){
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    bool res = true;
    for(int i = 0 ; i < n ; i ++ ){
      if(c[i] == a[i] || c[i] == b[i]) continue;
      res = false;
    }
    if(res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}