#include<bits/stdc++.h>

using namespace std;

vector<int> a={4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(auto &nx : a){
    if(n%nx==0){cout << "YES\n";return 0;}
  }
  cout << "NO\n";
  return 0;
}