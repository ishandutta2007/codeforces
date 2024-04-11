#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  int c=0;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    if(v+k<=5){c++;}
  }
  cout << c/3 << '\n';
  return 0;
}