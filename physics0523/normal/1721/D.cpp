#include<bits/stdc++.h>

using namespace std;

using pv=pair<vector<int>,vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    vector<pv> v={make_pair(a,b)};
    int res=0;
    for(int tg=29;tg>=0;tg--){
      bool ok=true;
      vector<pv> nv;
      for(auto &nx : v){
        vector<int> a0,a1;
        vector<int> b0,b1;
        for(auto &ny : nx.first){
          if(ny&(1<<tg)){a1.push_back(ny);}
          else{a0.push_back(ny);}
        }
        for(auto &ny : nx.second){
          if(ny&(1<<tg)){b1.push_back(ny);}
          else{b0.push_back(ny);}
        }
        if(a0.size()!=b1.size()){ok=false;break;}
        if(!a0.empty()){nv.push_back({a0,b1});}
        if(!b0.empty()){nv.push_back({a1,b0});}
      }

      if(ok){
        v=nv;
        res|=(1<<tg);
      }
    }
    cout << res << "\n";
  }
  return 0;
}