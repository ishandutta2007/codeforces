#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  set<char> x,o;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<n;j++){
      if(i==j || i==(n-1-j)){
        x.insert(s[j]);
      }
      else{
        o.insert(s[j]);
      }
    }
  }
  if(x.size()>1){cout << "NO\n";return 0;}
  if(o.size()>1){cout << "NO\n";return 0;}
  if((*x.begin())==(*o.begin())){cout << "NO\n";return 0;}
  cout << "YES\n";
  return 0;
}