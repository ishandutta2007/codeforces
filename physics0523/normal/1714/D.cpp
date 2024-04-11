#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while(q>0){
    q--;
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> t(n);
    for(auto &nx : t){cin >> nx;}
    int sta=0;
    vector<pi> res;
    while(sta<s.size()){
      int id=-1,ns=-1;
      for(int i=0;i<n;i++){
        for(int nsta=sta+t[i].size();nsta>=sta+1;nsta--){
          if(s.size()<nsta){continue;}
          bool fl=true;
          for(int j=0;j<t[i].size();j++){
            int sp=nsta-(t[i].size()-j);
            if(!(0<=sp && sp<s.size())){fl=false;break;}
            if(s[sp]!=t[i][j]){fl=false;break;}
          }
          if(fl){
            if(ns<nsta){ns=nsta;id=i;}
          }
        }
      }

      if(id==-1){break;}
      res.push_back({id+1,ns-t[id].size()+1});
      sta=ns;
    }

    if(sta!=s.size()){cout << "-1\n";continue;}
    cout << res.size() << "\n";
    for(auto &nx : res){
      cout << nx.first << " " << nx.second << "\n";
    }
  }
  return 0;
}