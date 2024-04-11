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
    vector<int> a(n);
    vector<vector<int>> mem(n+2);
    for(int i=0;i<n;i++){
      cin >> a[i];
      mem[a[i]].push_back(i);
    }
    for(auto &nx : mem){reverse(nx.begin(),nx.end());}
    vector<int> res;
    int p=0;
    while(1){
      if(mem[0].empty()){
        for(int i=p;i<n;i++){res.push_back(0);}
        break;
      }
      int ul;
      for(int i=0;;i++){
        if(mem[i].empty()){ul=i-1;break;}
      }
      res.push_back(ul+1);
      for(int i=0;i<=ul;i++){p=max(p,mem[i].back()+1);}
      //cout << ul << ' ' << p << '\n';
      for(int i=ul;i>=0;i--){
        while((!mem[i].empty()) && mem[i].back()<p){mem[i].pop_back();}
      }
    }
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}