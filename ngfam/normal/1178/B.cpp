#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  string s; cin >> s;
  long long w = 0, wo = 0, wow = 0;

  for(int i = 1; i < s.size(); ++i) {
    if(s[i - 1] == 'v' && s[i] == 'v') {
      wow += wo;
    }
    if(s[i] == 'o') {
      wo += w;
    }
    if(s[i - 1] == 'v' && s[i] == 'v') {
      w++;
    }
  }

  cout << wow;

  return 0;
}