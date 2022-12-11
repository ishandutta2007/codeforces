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
  for(int t = 0; t < tc;t  ++ ){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int res = 0;
    for(int i = 0 ; i < 3; i ++ ){
      if(a[i] > 0){
        res ++ ;
        a[i] -- ;
      }
    }
    for(int i = 0 ; i < 3; i ++ ) for(int j = 2; j >= i + 1; j -- ){
      if(a[i] > 0 && a[j] > 0){
        res ++ ;
        a[i]--;
        a[j]--;
      }
    }
    if(a[0] > 0 && a[1] > 0 && a[2] > 0){
      res ++ ;
    }
    cout << res << "\n";
  }
  return 0;
}