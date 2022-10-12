#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<string,long long> mp;
  vector<string> s(n);
  vector<long long> v(n);
  for(int i=0;i<n;i++){
    cin >> s[i] >> v[i];
    mp[s[i]]+=v[i];
  }
  long long mxm=0;
  for(auto &nx : mp){
    mxm=max(mxm,nx.second);
  }
  map<string,long long> fl;
  for(auto &nx : mp){
    if(nx.second==mxm){fl[nx.first]=1;}
  }
  map<string,long long> cmp;
  for(int i=0;i<n;i++){
    cmp[s[i]]+=v[i];
    if(cmp[s[i]]>=mxm && fl[s[i]]){
      cout << s[i] << '\n';
      return 0;
    }
  }
  return 0;
}