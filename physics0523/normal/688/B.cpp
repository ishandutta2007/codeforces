#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  cout << s;
  reverse(s.begin(),s.end());
  cout << s << '\n';
  return 0;
}