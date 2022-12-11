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
    int n;
    cin >> n;
    int x;
    int res = 0;
    int tt = 0;
    for(int i = 0 ; i < n ; i ++ ){
      cin >> x;
      if(x%2 == 1){
        tt ++ ;
      }
    }
    if((tt < n || tt % 2 == 1) && tt > 0){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
  return 0;
}