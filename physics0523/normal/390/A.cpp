#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  set<int> x,y;
  for(int i=0;i<n;i++){
    int p,q;
    cin >> p >> q;
    x.insert(p);
    y.insert(q);
  }
  cout << min(x.size(),y.size()) << "\n";
  return 0;
}