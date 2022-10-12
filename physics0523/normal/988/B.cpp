#include<bits/stdc++.h>

using namespace std;

bool jud(string s,string t){
  t.push_back('*');
  for(int i=0;i<t.size();i++){
    for(int j=0;j<s.size();j++){
      if(s[j]!=t[i+j]){break;}
      if(j==s.size()-1){return true;}
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int,string>> s(n);
  for(auto &nx : s){
    cin >> nx.second;
    nx.first=nx.second.size();
  }
  sort(s.begin(),s.end());
  vector<string> res;
  for(auto &nx : s){res.push_back(nx.second);}
  for(int i=1;i<n;i++){
    if(!jud(res[i-1],res[i])){cout << "NO\n";return 0;}
  }
  cout << "YES\n";
  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}