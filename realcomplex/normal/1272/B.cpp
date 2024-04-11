#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int L, R, U, D;

int main(){
  fastIO;
  int q;
  cin >> q;
  for(int i = 0 ; i< q; i ++ ){
    string t;
    cin >> t;
    L = R = U = D = 0;
    for(char x : t){
      if(x == 'L') L ++ ;
      if(x == 'R') R ++ ;
      if(x == 'U') U ++ ;
      if(x == 'D') D ++ ;
    }
    L=min(L,R);
    R=min(L,R);
    U=min(D,U);
    D=min(U,D);
    if(L == 0){
      U = min(U, 1);
      D = min(D, 1);
    }
    if(U == 0){
      L = min(L, 1);
      R = min(R, 1);
    }
    L=min(L,R);
    R=min(L,R);
    U=min(D,U);
    D=min(U,D);
    cout << L + U + R + D << "\n";
    for(int i = 0 ; i < L ;i ++ )
      cout << 'L';
    for(int i = 0 ; i < U ;i ++ )
      cout << 'U';
    for(int i = 0 ; i < R; i ++ )
      cout << 'R';
    for(int i = 0; i < D; i ++ )
      cout << 'D';
    cout << "\n";
  }
  return 0;
}