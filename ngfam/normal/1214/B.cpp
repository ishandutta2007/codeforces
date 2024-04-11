#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int b, g, n; cin >> b >> g >> n;
  set < pair < int, int > > w;

  for(int x = 0; x <= n; ++x) {
    int y = n - x;
    if(x <= b && y <= g) w.emplace(x, y);
  }

  cout << w.size();

  return 0;
}