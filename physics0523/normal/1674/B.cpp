#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int id=1;
  map<string,int> mp;
  for(char i='a';i<='z';i++){
    for(int j='a';j<='z';j++){
      if(i==j){continue;}
      string cs;
      cs.push_back(i);
      cs.push_back(j);
      mp[cs]=id;
      id++;
    }
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    cout << mp[s] << '\n';
  }
  return 0;
}