#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
  string s; cin >> s;

  for(int i = 0; i < 5; ++i) {
    string r; cin >> r;
    if(r[0] == s[0] || r[1] == s[1]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

	return 0;
}