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
  vector<int> c(n);
  char p;
  for(int i = 0 ; i < n; i ++ ){
    cin >> p;
    c[i] = (p == 'B');
  }
  for(int i = 0 ; i < 2; i ++ ){
    vector<int> t = c;
    vector<int> sol;
    for(int j = 0 ; j + 1 < n; j ++ ){
      if(t[j] != i){
        t[j] ^= 1;
        t[j + 1] ^= 1;
        sol.push_back(j + 1);
      }
    }
    if(t[n - 1] == i){
      cout << sol.size() << "\n";
      for(auto x : sol)
        cout << x << " ";
      cout << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}