#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  vector<pi> vp;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(i%2){vp.push_back({i,m-j-1});}
      else{vp.push_back({i,j});}
    }
  }
  int cp=0;
  for(int i=0;i<k;i++){
    int len=2;
    if(i==k-1){len=n*m-cp;}
    cout << len;
    for(int j=0;j<len;j++){
      cout << ' ' << vp[cp].first+1 << ' ' << vp[cp].second+1;
      cp++;
    }
    cout << '\n';
  }
  return 0;
}