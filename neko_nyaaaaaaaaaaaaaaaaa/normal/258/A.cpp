#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      string s;
      cin >> s;
      
      for (int i = 0; i < s.size(); i++) {
      	if (s[i] == '0') {
      		s.erase(i, 1);
      		cout << s;
      		return 0;
      	}
      }
	
      s.pop_back();
      cout << s;
      
      return 0;
}