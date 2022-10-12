#include<bits/stdc++.h>

using namespace std;

void shift(int l,int r,vector<int> &a){
  int v=a[r];
  for(int i=r;i>l;i--){a[i]=a[i-1];}
  a[l]=v;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
      int mi=i;
      for(int j=i+1;j<n;j++){
        if(a[mi]>a[j]){mi=j;}
      }
      if(mi!=i){
        res.push_back({i+1,mi+1});
        shift(i,mi,a);
      }
    }
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
      cout << res[i].first << ' ' << res[i].second << ' ' << (res[i].second-res[i].first+1)-1 << '\n';
    }
  }
  return 0;
}