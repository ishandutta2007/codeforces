#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    string s;
    cin >> s;
    int l0 = 0, l1 = 0;
    for(char x : s){
      if(x == '0') l0 ++ ;
      else l1 ++ ;
    }
    int ans = min(l0, l1);
    if(ans % 2 == 0)
      cout << "NET\n";
    else
      cout << "DA\n";
  }
  return 0;
}