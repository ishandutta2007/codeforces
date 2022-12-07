#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n; cin >> n;
  vector < int > a;

  while(n--) {
    int x; cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0; i < a.size(); ++i) {
    bool get = false;
    for(int j = 0; j < i; ++j) {
      if(a[i] % a[j] == 0) get = true;
    }
    if(!get) ++ans;
  }

  cout << ans;

  return 0;
}