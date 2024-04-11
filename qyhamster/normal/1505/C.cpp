#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  string s;
  cin >> s;
  bool ok = 1;
  for(int i = 2; i < s.length(); i++) {
    if(s[i] - 'A' != (s[i-1] - 'A' + s[i-2] - 'A')% 26) ok = 0;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}