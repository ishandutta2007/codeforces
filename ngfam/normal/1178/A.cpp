#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, x; cin >> n >> x; 

  vector < int > indices(1, 1);

  int s = x, tot = x;
  for(int i = 1; i < n; ++i) {
    int w; cin >> w;
    if(w * 2 <= x) s += w, indices.emplace_back(i + 1);
    tot += w;
  }

  if(s * 2 > tot) {
    cout << indices.size() << endl;
    for(auto x : indices) cout << x << " ";
  }
  else cout << 0;

  return 0;
}