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
  int z = 0, e = 0, r = 0, o = 0, n = 0;
  int m;
  cin >> m;
  char f;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> f;
    if(f == 'z') z ++ ;
    else if(f == 'e') e ++ ;
    else if(f == 'r') r ++ ;
    else if(f == 'o') o ++ ;
    else n ++ ;
  }
  for(int i = 0 ; i < n; i ++ ){
    cout << "1 ";
  }
  for(int i = 0; i < z; i ++ )
    cout << "0 ";
  return 0;
}