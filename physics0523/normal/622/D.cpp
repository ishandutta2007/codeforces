#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  deque<int> od,ev;
  ev.push_back(n);
  for(int i=1;i<n;i++){
    if(i%2){
      od.push_front(n-i);
      od.push_back(n-i);
    }
    else{
      ev.push_front(n-i);
      ev.push_back(n-i);
    }
  }
  cout << n;
  for(auto &nx : od){
    cout << ' ' << nx;
  }
  for(auto &nx : ev){
    cout << ' ' << nx;
  }cout << '\n';
  return 0;
}