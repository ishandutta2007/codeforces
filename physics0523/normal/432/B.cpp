#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n),y(n);
  vector<int> bk(131072,0);
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
    bk[x[i]]++;
  }
  for(int i=0;i<n;i++){
    int h=(n-1),a=(n-1);
    int del=bk[y[i]];
    cout << h+del << ' ' << a-del << '\n';
  }
  return 0;
}