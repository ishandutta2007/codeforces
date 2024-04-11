#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  string s;
  cin >> n >> k >> s;
  char cur='-';
  int ch=0;
  map<char,int> mp;
  for(auto &nx : s){
    if(cur!=nx){cur=nx;ch=1;}
    else{ch++;}
    if(k==ch){
      ch=0;
      mp[cur]++;
    }
  }
  int res=0;
  for(auto &nx : mp){
    res=max(res,nx.second);
  }
  cout << res << '\n';
  return 0;
}