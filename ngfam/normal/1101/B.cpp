#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  string s; cin >> s;
  int n = s.size(); 

  int cnt = 0, posx = -1, posy = -1;

  for(int i = 0; i < n; ++i) {
    if(s[i] == '[' && cnt == 0) ++cnt;
    if(s[i] == ':' && cnt == 1) {
      posx = i;
      break;
    }
  }

  cnt = 0;
  for(int i = n - 1; i >= 0; --i) {
    if(s[i] == ']' && cnt == 0) ++cnt;
    if(s[i] == ':' && cnt == 1) {
      posy = i;
      break;
    }
  }

  if(posx >= posy || min(posx, posy) == -1) {
    cout << -1;
    return 0;
  }

  cnt = 4;

  for(int i = posx; i <= posy; ++i) cnt += (s[i] == '|');

  cout << cnt;

  return 0;
}