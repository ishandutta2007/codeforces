#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<pi>> pf(1000005);
  for(int i=2;i<1000005;i++){
    if(!pf[i].empty()){continue;}
    for(int j=i;j<1000005;j+=i){
      int c=0,mem=j;
      while(mem%i==0){
        mem/=i;
        c++;
      }
      pf[j].push_back({i,c});
    }
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    map<int,vector<pi>> mp;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      for(auto &nx : pf[v]){
        mp[nx.first].push_back({i,nx.second});
      }
    }
    int res=0;
    for(auto &nx : mp){
      if(nx.second.size()==n){
        int mi=1e9;
        for(auto &ny : nx.second){
          mi=min(mi,ny.second);
        }
        vector<int> wa;
        for(auto &ny : nx.second){
          if(mi==ny.second){wa.push_back(ny.first);}
        }
        // for(auto &nx : wa){cout << nx << ',';}cout << '\n';
        // cout << '<' << res << ">\n";
        for(int i=0;i<wa.size();i++){
          res=max(res,(n+wa[(i+1)%wa.size()]-wa[i]-1)%n);
        }
      }
      else{
        vector<int> wa;
        for(auto &ny : nx.second){
          wa.push_back(ny.first);
        }
        int ch=1;
        res=max(res,ch);
        int ws=wa.size();
        // for(auto &nx : wa){cout << nx << ':';}cout << '\n';
        // cout << '<' << res << ">\n";
        for(int i=1;i<3*wa.size();i++){
          if((wa[(i-1)%ws]+1)%n==wa[i%ws]){ch++;}
          else{ch=1;}
          res=max(res,ch);
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}