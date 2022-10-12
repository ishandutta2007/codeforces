#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int j=0;
  for(int i=1;j<n;i++){
    cout << s[j];
    j+=i;
  }cout << '\n';
  return 0;
}