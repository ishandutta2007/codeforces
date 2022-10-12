#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int r1=0,r2=0;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    r1|=v;
  }
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    r2|=v;
  }
  cout << r1+r2 << '\n';
  return 0;
}