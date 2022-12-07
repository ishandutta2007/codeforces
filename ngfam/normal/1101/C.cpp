#include <bits/stdc++.h>

using namespace std;



int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int T;
  cin >> T;

  while(T--) {
    int n; cin >> n;
    vector < int > color(n, -1);
    vector < pair < pair < int, int >, int > > a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first.first >> a[i].first.second, a[i].second = i;
    
    sort(a.begin(), a.end());
    set < pair < int, int > > myset; 
    
    bool able = true;

    int variety = 1;

    for(int i = 0; i < n; ++i) {
      auto p = a[i].first;
      auto it = myset.lower_bound(make_pair(p.first, -1));
      if(it == myset.end()) {
        color[a[i].second] = variety;
        variety = 3 - variety;
        myset.emplace(p.second, a[i].second);
        continue;
      }
      color[a[i].second] = color[it -> second];
      myset.emplace(p.second, a[i].second);
    }

    if(*max_element(color.begin(), color.end()) != 2) able = false;

    if(!able) {
      cout << -1 << '\n';
    }
    else {
      for(int x : color) cout << x << " ";
      cout << '\n';
    }
  }
	
  return 0;
}