#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  vector<vector<int>> res(n,vector<int>(n,-1));
  for(int i=0;i<n;i++){
    int cnt=a[i];
    int tg=i;
    for(int j=i;j<n;j++){
      for(int k=tg;k>=0;k--){
        if(cnt==0 || res[j][k]!=-1){break;}
        res[j][k]=a[i];
        tg=k;
        cnt--;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(j){cout << ' ';}
      cout << res[i][j];
    }cout << '\n';
  }
  return 0;
}