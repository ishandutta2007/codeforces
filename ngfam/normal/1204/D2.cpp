#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  string s; 
  cin >> s;

  vector < int > oneminuszero(s.size() + 1, 0);
  for(int i = s.size() - 1; i >= 0; --i) {
    int val = oneminuszero[i + 1];
    if(s[i] == '0') {
      val--;
      oneminuszero[i] = min(val, -1);
    }
    else {
      val++;
      oneminuszero[i] = min(val, 1);
    }
  }

  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '0') continue;

    if(oneminuszero[i] > 0) {
      s[i] = '0';
    }
  }

  cout << s;

  return 0;
}