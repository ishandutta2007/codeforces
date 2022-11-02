#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = "";
  int ans = 0;
  for (int i = 0; i < n; i += 2){
    if (s[i] == s[i + 1])
      ans += 1;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i += 2){
    if (s[i] == s[i + 1])
      cout << "ab";
    else
      cout << s[i] << s[i + 1];
  }
  return 0;
}