#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    map<char,int> mp;
    for(int i=0;i<2;i++){
      cin >> s;
      for(int j=0;j<2;j++){
        mp[s[j]]++;
      }
    }
    vector<int> a;
    for(auto &nx : mp){a.push_back(nx.second);}
    sort(a.begin(),a.end());
    a.pop_back();
    int res=a.size();
    cout << res << "\n";
  }
  return 0;
}