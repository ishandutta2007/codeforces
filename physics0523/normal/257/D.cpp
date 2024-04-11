#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  string s;
  for(auto &nx : a){
    cin >> nx;
    s.push_back('+');
  }
  int sig=0;
  for(int i=n-1;i>=0;i--){
    if(sig<=0){
      s[i]='+';
      sig+=a[i];
    }
    else{
      s[i]='-';
      sig-=a[i];
    }
  }
  if(sig<0){
    for(auto &nx : s){
      nx=('+'+'-')-nx;
    }
  }
  cout << s << '\n';
  return 0;
}