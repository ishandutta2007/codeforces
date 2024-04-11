#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
	
	list<int> ans;
	string s;
	cin >> s;
	ans.push_back(1);
	list<int>::iterator it = ans.begin();
	for (int i = 0; i < s.size()-1; i++) {
	      if (s[i] == 'l') {
	            ans.insert(it, i+2);
	            it--;
	      } else {
	            it++;
	            ans.insert(it, i+2);
	            it--;
	      }
	}
	for (it = ans.begin(); it != ans.end(); it++) {
	      cout << *it << "\n";
	}
	 
	return 0;
}