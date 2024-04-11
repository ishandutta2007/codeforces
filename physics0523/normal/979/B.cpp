#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int f(string s,int n){
  sort(s.begin(),s.end());
  if(s.size()==1){return 1;}
  if(s[0]==s[s.size()-1]){
    if(n==1){return (s.size()-1);}
    return s.size();
  }
  map<char,int> mp;
  for(auto &nx : s){mp[nx]++;}
  int r=0;
  for(auto &nx : mp){r=max(r,nx.second);}
  return min(r+n,(int)s.size());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  vector<pi> vp;
  cin >> s;
  vp.push_back({f(s,n),0});
  cin >> s;
  vp.push_back({f(s,n),1});
  cin >> s;
  vp.push_back({f(s,n),2});
  sort(vp.begin(),vp.end());
  if(vp[1].first==vp[2].first){cout << "Draw\n";return 0;}
  if(vp[2].second==0){cout << "Kuro\n";}
  if(vp[2].second==1){cout << "Shiro\n";}
  if(vp[2].second==2){cout << "Katie\n";}
  return 0;
}