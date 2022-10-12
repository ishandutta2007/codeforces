#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int k,n,m;
    cin >> k >> n >> m;
    vector<int> a(n),b(m);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int> res;
    while(!a.empty() || !b.empty()){
      if(!a.empty() && a.back()==0){
        k++;
        res.push_back(0);
        a.pop_back();
        continue;
      }
      if(!b.empty() && b.back()==0){
        k++;
        res.push_back(0);
        b.pop_back();
        continue;
      }
      if(!a.empty() && a.back()<=k){
        res.push_back(a.back());
        a.pop_back();
        continue;
      }
      if(!b.empty() && b.back()<=k){
        res.push_back(b.back());
        b.pop_back();
        continue;
      }
      res.clear();
      res.push_back(-1);
      break;
    }
    for(int i=0;i<res.size();i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}