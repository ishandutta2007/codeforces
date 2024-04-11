#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,s;
    cin >> n >> s;
    int nd=(n+2)/2;
    cout << s/nd << '\n';
  }
  return 0;
}