#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    map<int,vector<long long>> mp;
    long long n;
    cin >> n;
    for(long long i=0;i<n;i++){
      int v;
      cin >> v;
      mp[v].push_back(i);
    }
    long long res=0;
    for(auto &nx : mp){
      long long csig=0;
      for(auto &nv : nx.second){
        //cout << nv << ',';
        res+=(csig)*(n-nv);
        csig+=(1+nv);
      }//cout << '\n';
    }
    cout << res << '\n';
  }
  return 0;
}