#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> sf(n);
    for(auto &nx : sf){cin >> nx.first;}
    for(auto &nx : sf){cin >> nx.second;}
    sort(sf.begin(),sf.end());
    for(auto &nx : sf){
      if(nx.first<=k){k+=nx.second;}
    }
    cout << k << '\n';
  }
  return 0;
}