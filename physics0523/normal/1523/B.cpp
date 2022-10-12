#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    cout << 3*n << '\n';
    for(int i=1;i<=n;i+=2){
      cout << 1 << ' ' << i << ' ' << i+1 << '\n';
      cout << 2 << ' ' << i << ' ' << i+1 << '\n';
      cout << 2 << ' ' << i << ' ' << i+1 << '\n';
      cout << 1 << ' ' << i << ' ' << i+1 << '\n';
      cout << 2 << ' ' << i << ' ' << i+1 << '\n';
      cout << 2 << ' ' << i << ' ' << i+1 << '\n';
    }
  }
  return 0;
}