#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  map<int,int>cnt;
  int k;
  int ans = 0;
  for(int j = 0;j<n;j++){
    cin >> k;
    cnt[k]++;
    ans = max(ans,cnt[k]);     
  }
  cout << ans << "\n";
  return 0;
}