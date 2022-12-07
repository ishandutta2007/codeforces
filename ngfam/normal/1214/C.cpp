#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n; cin >> n;

  string s;
  cin >> s;

  int sum = 0, fixed = 0;


  for(auto &c : s) {
    if(c == '(') sum++;
    else if(c == ')') {
      if(sum == 0) {
        if(fixed) {
          cout << "No";
          return 0;
        }
        else {
          fixed = 1;
        }
      }  
      else sum--;
    }
  }

  if(fixed) sum--;
  if(sum != 0) cout << "No";
  else cout << "Yes";
  return 0;
}