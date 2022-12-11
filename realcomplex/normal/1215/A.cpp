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
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  int low = 0;
  int high = 0;
  int nn = n;
  if(k1 < k2){
    for(int i = 0 ; i < a1; i ++ ){
      if(n >= k1){
        n -= k1;
        high ++ ;
      }
    }
    for(int i = 0 ;i < a2; i ++ ){
      if(n >= k2){
        n -= k2;
        high ++ ;
      }
    }
  }
  else{
    for(int i = 0 ;i < a2; i ++ ){
      if(n >= k2){
        n -= k2;
        high ++ ;
      }
    }
    for(int i = 0 ; i < a1; i ++ ){
      if(n >= k1){
        n -= k1;
        high ++ ;
      }
    }
  }
  nn -= (k1 - 1) * a1;
  nn -= (k2 - 1) * a2;
  nn = max(nn, 0);
  cout << nn << " " << high << "\n";
  return 0;
}