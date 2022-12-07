#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
	
  int n; cin >> n;
  vector < pair < int, pair < int, int > > > vec(n);

  vector < int > num;

  for(auto &p : vec) {
    char c; 
    cin >> c >> p.second.first >> p.second.second;
    p.first = (c == '?');
    if(p.second.first > p.second.second) swap(p.second.first, p.second.second);
    num.emplace_back(p.second.first);
  }

  sort(num.begin(), num.end());
  num.erase(unique(num.begin(), num.end()), num.end());

  vector < int > bitcnt(n + 5, 0), bitmax(n + 5, -1);

  int sum = 0;

  for(auto &p : vec) {
    p.second.first = lower_bound(num.begin(), num.end(), p.second.first) - num.begin() + 1;
    if(p.first == 0) {
      ++sum;
      for(int x = p.second.first; x <= n; x += x & -x) {
        bitcnt[x]++;
        bitmax[x] = max(bitmax[x], p.second.second);
      }
    }
    else {
      int cnt = 0, mx = -1;
      for(int x = p.second.first; x > 0; x &= x - 1) {
        cnt += bitcnt[x];
        mx = max(mx, bitmax[x]);
      }
      
      if(cnt < sum || mx > p.second.second) {
        cout << "NO\n";
      }
      else{
        cout << "YES\n";
      }
    } 
  }

  return 0;
}