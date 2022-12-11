#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<int,int> sol;

int main(){
  fastIO;
  int q;
  cin >> q;
  int a;
  for(int i = 0 ; i < q; i ++ ){
    cin >> a;
    if(__builtin_popcount(a+1) == 1){
      if(sol.count(a)) cout << sol[a] << "\n";
      else{
        int r = 1;
        for(int p = 2; p * p <= a; p ++ )
          if(a%p==0){
            r=a/p;
            break;
          }
        cout << r << "\n";
      }
    }
    else{
      int lg = 1;
      while(lg <= a){
        lg *= 2;
      }
      cout << lg - 1 << "\n";
    }
  }
  return 0;
}