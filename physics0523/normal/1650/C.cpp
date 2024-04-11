#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;
using ppl=pair<pl,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int m,n;
    cin >> m >> n;
    vector<ppl> pv(n);
    int id=1;
    for(auto &nx : pv){
      cin >> nx.first.second >> nx.first.first;
      nx.second=id;id++;
    }
    sort(pv.begin(),pv.end());
    while(pv.size()>2*m){pv.pop_back();}
    long long res=0;
    for(auto &nx : pv){
      res+=nx.first.first;
      swap(nx.first.first,nx.first.second);
    }
    cout << res << '\n';
    sort(pv.begin(),pv.end());
    for(int i=0;i<m;i++){
      cout << pv[i].second << ' ';
      cout << pv[2*m-i-1].second << '\n';
    }
  }
  return 0;
}