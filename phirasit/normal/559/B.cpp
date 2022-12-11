#include <iostream>

using namespace std;

string s1, s2;

string sort_string(string s) {
  int l = s.length();
  if(l % 2) {
    return s;
  }
  string t1, t2;
  t1 = sort_string(s.substr(0, l/2));
  t2 = sort_string(s.substr(l/2, l/2));
  return t1 < t2 ? t1 + t2 : t2 + t1;
}
int main() {
  cin >> s1 >> s2;
  cout << (sort_string(s1) == sort_string(s2) ? "YES" : "NO") << endl;
  return 0;
}