#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int dum;
    cin >> dum;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << '\n';
  }
}