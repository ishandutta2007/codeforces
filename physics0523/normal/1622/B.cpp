#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    string s;
    cin >> s;
    vector<pair<int,int>> dat;
    for(int i=0;i<n;i++){
      int cv=p[i];
      if(s[i]=='1'){cv+=1000000000;}
      dat.push_back({cv,i});
    }
    sort(dat.begin(),dat.end());
    vector<int> q(n);
    for(int i=0;i<n;i++){
      q[dat[i].second]=i+1;
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << q[i];
    }cout << '\n';
  }
  return 0;
}