#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){cin >> a[j][i];}
    }

    bool nochange=true;
    for(int i=0;i<n;i++){
      vector<pi> pv;
      for(int j=0;j<m;j++){pv.push_back({a[j][i],j});}
      sort(pv.begin(),pv.end());
      bool jud=true;
      for(int j=0;j<m;j++){
        if(pv[j].second!=j){jud=false;break;}
      }
      if(jud){continue;}

      nochange=false;
      map<int,unordered_set<int>> mp;
      for(int j=0;j<m;j++){
        mp[a[j][i]].insert(j);
      }
      vector<int> err;
      int cp=0;
      for(auto &nx : mp){
        for(int p=0;p<nx.second.size();p++){
          if(nx.second.find(cp)==nx.second.end()){err.push_back(cp);}
          cp++;
        }
      }
      if(err.size()>2){cout << "-1\n";break;}
      swap(a[err[0]],a[err[1]]);
      bool isok=true;
      for(int p=0;p<n;p++){
        for(int q=1;q<m;q++){
          if(a[q-1][p]>a[q][p]){isok=false;}
        }
      }
      if(isok){
        cout << err[0]+1 << ' ' << err[1]+1 << '\n';
      }
      else{cout << "-1\n";}
      break;
    }
    if(nochange){cout << "1 1\n";}
  }
  return 0;
}