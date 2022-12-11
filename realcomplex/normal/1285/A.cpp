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
  int l = 0, r = 0;
  char q;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> q;
    if(q == 'L')
      l ++ ;
    else
      r ++ ;
  }
  cout << l + r + 1;
  return 0;
}