#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main(){
  int n,m;
  cin >> n >> m;
  int l,r;
  for(int i = 0;i<m;i++){
    cin >> l >> r;
    for(int j = l;j<=r;j++)cnt[j]++;
  } 
  for(int i = 1;i<=n;i++)
    if(cnt[i]==0 or cnt[i]>1){
      cout << i << " " << cnt[i] << "\n";
      return 0;
    }
  cout << "OK\n";
  return 0;
}