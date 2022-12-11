#include <bits/stdc++.h>

using namespace std;

int cnt[101];

int main(){
  int n;
  cin >> n;
  int l[n],r[n];
  for(int i = 0;i<n;i++){
    cin >> l[i] >> r[i];
    for(int j = l[i];j<r[i];j++)
      cnt[j]++;
  }
  int ans = 0;
  for(int i = l[0];i<r[0];i++){
    if(cnt[i]==1)ans++;
  }
  cout << ans << "\n";
  return 0;
}