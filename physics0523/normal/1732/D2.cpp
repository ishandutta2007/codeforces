#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<long long,long long> mp;
  map<long long,vector<long long>> inc;
  map<long long,set<long long>> ist;
  set<long long> st;
  set<long long> van;
  st.insert(0);

  long long q;
  cin >> q;
  while(q>0){
    q--;
    string s;
    long long x;
    cin >> s >> x;
    if(s[0]=='+'){
      st.insert(x);
      van.erase(x);
      for(auto &nx : inc[x]){ist[nx].erase(x);}
    }
    else if(s[0]=='-'){
      st.erase(x);
      van.insert(x);
      for(auto &nx : inc[x]){
        ist[nx].insert(x);
      }
    }
    else{
      long long cur=mp[x];
      while(st.find(cur)!=st.end() && van.find(cur)==van.end()){
        inc[cur].push_back(x);
        // cerr << x << "," << cur << "\n";
        cur+=x;
      }
      mp[x]=cur;

      if(!ist[x].empty()){
        cur=min(cur,(*ist[x].begin()));
      }
      cout << cur << "\n";
    }
  }

  return 0;
}