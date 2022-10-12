#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string,int> mp;
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    if(mp[s]==0){
      cout << "OK\n";
    }
    else{
      cout << s << mp[s] << '\n';
    }
    mp[s]++;
  }
  return 0;
}