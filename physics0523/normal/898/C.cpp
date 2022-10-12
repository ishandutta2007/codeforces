#include<bits/stdc++.h>

using namespace std;

int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);
  unordered_map<string,unordered_set<string>> mp;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    string cpt;
    cin >> cpt;
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
      string str;
      cin >> str;
      mp[cpt].insert(str);
    }
  }
  cout << mp.size() << '\n';
  for(auto &nx : mp){
    cout << nx.first;
    vector<string> sv,sres;
    for(auto ny : nx.second){
      reverse(ny.begin(),ny.end());
      sv.push_back(ny);
    }
    sort(sv.begin(),sv.end());
    int cnt=sv.size();
    for(int i=0;i<cnt;i++){
      if(i!=cnt-1 && sv[i].size()<=sv[i+1].size() && equal(sv[i].begin(),sv[i].end(),sv[i+1].begin())){continue;}
      reverse(sv[i].begin(),sv[i].end());
      sres.push_back(sv[i]);
    }
    cout << ' ' << sres.size();
    for(auto &nx : sres){cout << ' ' << nx;}
    cout << '\n';
  }
  return 0;
}