#include <iostream>

using namespace std;

const string WORD = "CODEFORCES";
string str;

int main() {
  cin >> str;
  bool found = false;
  for(int i = 0;i < str.length();i++) {
    for(int j = i;j < str.length();j++) {
      string nw = "";
      for(int k = 0;k < str.length();k++) {
        if(k < i || j < k) {
          nw += str[k];
        }
      }
      if(nw == WORD) {
        found = true;
      }
    }
  }
  cout << (found ? "YES" : "NO") << endl;
  return 0;
}