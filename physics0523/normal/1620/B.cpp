#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long h,w;
    cin >> h >> w;
    vector<vector<long long>> v(4);
    long long res=0;
    for(int i=0;i<4;i++){
      int c;
      cin >> c;
      v[i].resize(c);
      for(int j=0;j<c;j++){
        cin >> v[i][j];
      }
      sort(v[i].begin(),v[i].end());
      if(i<=1){
        res=max(w*(v[i][c-1]-v[i][0]),res);
      }
      else{
        res=max(h*(v[i][c-1]-v[i][0]),res);
      }
    }
    cout << res << '\n';
  }
  return 0;
}