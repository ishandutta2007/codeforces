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
  int q;
  cin >> q;
  for(int i = 0 ; i< q; i ++ ){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if(a[0] == a[1] && a[1] == a[2])
      cout << 0 << "\n";
    else if(a[0] == a[1])
      cout << 2 * max(0, (a[2] - 1) - (a[1] + 1)) << "\n";
    else if(a[2] == a[1])
      cout << 2 * max(0, (a[1] - 1) - (a[0] + 1)) << "\n";
    else
      cout << 2 * (a[2] - a[0] - 2) << "\n";
  }
  return 0;
}