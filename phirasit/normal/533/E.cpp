#include <iostream>

using namespace std;

string s1, s2;
int n;

int main() { 

  ios::sync_with_stdio( false );
  cin >> n >> s1 >> s2;

  while ( !s1.empty() and s1.back() == s2.back() ) {
    s1.pop_back();
    s2.pop_back();
  }

  int idx = 0;
  while( idx < s1.size() and s1[idx] == s2[idx] ) {
    idx++;
  }

  s1 = s1.substr( idx );
  s2 = s2.substr( idx );

  int ans = 0;

  if ( s2[0] + s1 == s2 + s1.back() ) {
    ans++;
  } 
  if ( s1 + s2.back() == s1[0] + s2 ) {
    ans++;
  } 

  cout << ans << endl;

  return 0;
}