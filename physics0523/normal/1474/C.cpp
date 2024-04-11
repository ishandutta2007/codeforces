#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

void outres(vector<pi> &res){
  if(res.empty()){
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  cout << res[0].first+res[0].second << '\n';
  for(auto &nx : res){cout << nx.first << ' ' << nx.second << '\n';}
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
    multiset<int> ms;
    for(int i=0;i<2*n;i++){
      int v;
      cin >> v;
      ms.insert(v);
    }
    vector<pi> res;
    for(int i=0;i<n;i++){
      vector<pi> cres(n);
      multiset<int> cms=ms;
      bool iserr=false;

      auto it=cms.end();it--;
      cres[0].first=(*it);cms.erase(it);
      for(int j=1;j<n;j++){
        auto mit=cms.end();mit--;
        int cval=(*mit);cms.erase(mit);
        if(i==j){
          cres[0].second=cval;
          auto nmit=cms.end();nmit--;
          cres[j].first=(*nmit);cms.erase(nmit);
        }
        else{cres[j].first=cval;}
        int tg=cres[j-1].first-cres[j].first;
        //cerr << i << ' ' << j << ' ' << cval << ' ' << tg << '\n';
        if(cms.find(tg)==cms.end()){iserr=true;break;}
        cres[j].second=tg;
        cms.erase(cms.find(tg));
      }
      if(iserr){continue;}
      if(!cms.empty()){cres[0].second=(*cms.begin());}
      res=cres;
      break;
    }
    outres(res);
  }
  return 0;
}