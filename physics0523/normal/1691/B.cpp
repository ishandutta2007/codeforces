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
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++){
      int s;
      cin >> s;
      mp[s].push_back(i);
    }
    vector<int> p(n+1);
    bool fl=false;
    for(auto &nx : mp){
      int sz=nx.second.size();
      if(sz==1){fl=true;break;}
      for(int i=0;i<sz;i++){
        p[nx.second[i]]=nx.second[(i+1)%sz];
      }
    }
    if(fl){cout << "-1\n";continue;}
    for(int i=0;i<n;i++){
      if(i){cout << " ";}cout << p[i+1];
    }cout << "\n";
  }
}