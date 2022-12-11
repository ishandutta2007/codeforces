#include <bits/stdc++.h>

using namespace std;

int cnt[1005];//count the number of wins

int main(){
  int n,k;
  cin >> n >> k;
  int l = n*k;
  int v = (n*(n-1))/2;
  if(l>v){
    cout << -1 << "\n";
    return 0;
  }
  cout << l << "\n";
  for(int i = 1;i<=n;i++){
    for(int j = i+1;j<=n;j++){
      if(cnt[i]<k){
        ++cnt[i];
        cout << i << " " << j << "\n";
      }
      else if(cnt[j]<k){
        ++cnt[j];
        cout << j << " " << i << "\n";
      }
    } 
  }
  return 0; 
}