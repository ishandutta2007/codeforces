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
    vector<int> p(n),res;
    for(auto &nx : p){cin >> nx;}
    vector<bool> fl(n+1,true);
    for(int i=n;i>=1;i--){
      if(!fl[i]){continue;}
      int ps=p.size();
      for(int j=ps-1;j>=0;j--){
        if(p[j]==i){
          for(int k=j;k<ps;k++){
            res.push_back(p[k]);
            fl[p[k]]=false;
          }
          for(int k=j;k<ps;k++){p.pop_back();}
          break;
        }
      }
    }

    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}