#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, x; 
  cin >> n >> x;

  vector < int > a;
  vector < bool > blocked(1 << n, false);

  if(x < (1 << n)) blocked[x] = blocked[0] = 1;
  

  set < int > avail;
  for(int i = 1; i < (1 << n); ++i) if(i != x) avail.emplace(i);

  int prefix = 0;
  
  while(!avail.empty()) {
    int val = *avail.begin();
    avail.erase(val);
    avail.erase(val ^ x);
    a.emplace_back(prefix ^ val);
    prefix = val;

  }

  cout << a.size() << endl;
  for(int x : a) cout << x << " ";

  return 0;
}