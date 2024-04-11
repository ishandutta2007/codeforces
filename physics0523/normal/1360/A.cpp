#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    int el=min(max(2*a,b),max(2*b,a));
    cout << el*el << '\n';
  }
  return 0;
}