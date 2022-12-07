#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, q;
  cin >> n >> q;

  vector < int > a(n);
  vector < pair < int, int > > steps;

  deque < int > dq;
  for(int &x : a) cin >> x, dq.push_back(x);

  int mx = *max_element(a.begin(), a.end());
  
  while(dq.front() != mx) {
    int x = dq.front(); dq.pop_front();
    int y = dq.front(); dq.pop_front();

    steps.emplace_back(x, y);
    dq.push_front(max(x, y));
    dq.push_back(min(x, y));
  }

  vector < int > res;
  while(dq.size()) {
    res.push_back(dq.front());
    dq.pop_front();
  }

  while(q--) {
    long long m; cin >> m;
    if(m <= steps.size()) {
      cout << steps[m - 1].first << " " << steps[m - 1].second << "\n";
    }
    else {
      m -= steps.size();
      m = (m % (n - 1));
      if(m == 0) m = n - 1;

      cout << mx << " " << res[m] << "\n";
    }
  }

  return 0;
}