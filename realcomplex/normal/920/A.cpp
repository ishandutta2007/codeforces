#include <bits/stdc++.h>

using namespace std;

void Solve(){
  int n,k;
  cin >> n >> k;
  int ans[n];
  for(int i = 0;i<n;i++)ans[i]=20000;
  int cur;
  int l;
  for(int i = 0;i<k;i++){
    cin >> cur;
    l=1;
    --cur;
    for(int j = cur;j>=0;j--){
      ans[j]=min(ans[j],l);
      l++;
    }
    l=1;
    for(int j = cur;j<n;j++){
      ans[j]=min(ans[j],l);
      l++;
    }
  }
  int v = 0;
  for(int i = 0;i<n;i++)v=max(v,ans[i]);
  cout << v << "\n";
}

int main(){
  std::ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while(q--)
    Solve();
  return 0;
}