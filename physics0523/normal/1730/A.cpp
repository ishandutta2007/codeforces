#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,c;
    cin >> n >> c;
    map<long long,long long> mp;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      mp[v]++;
    }
    long long res=0;
    for(auto &nx : mp){
      res+=min(nx.second,c);
    }
    cout << res << "\n";
  }
  return 0;
}