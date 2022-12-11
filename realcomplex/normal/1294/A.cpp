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
  for(int tt = 0 ;tt < testc; tt ++ ){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int t = a + b + c + n;
    if(t % 3 != 0)
      cout << "NO\n";
    else{
      t /= 3;
      if(a <= t && b <= t && c <= t)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}