#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n; string s;
  cin >> n >> s;

  vector < pair < int, int > > a(n);
  for(auto &p : a) cin >> p.first >> p.second;

  int ans = 0;
  for(int T = 0; T <= 10000; ++T){
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      if(T < a[i].second) {
        cnt += s[i] - '0';
      }
      else {
        cnt += (s[i] - '0') ^ (((T - a[i].second) / a[i].first + 1) % 2);
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans;

  return 0;
}