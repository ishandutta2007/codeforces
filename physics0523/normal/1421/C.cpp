#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  // cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int l=s.size();
    cout << "3\n";
    cout << "L 2\n";
    cout << "R 2\n";
    cout << "R " << 2*l-1 << '\n';
  }
  return 0;
}