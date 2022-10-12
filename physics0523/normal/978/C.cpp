#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  set<pl> sp;
  long long sig=0;
  for(int i=0;i<n;i++){
    sp.insert({sig,i+1});
    long long v;
    cin >> v;
    sig+=v;
  }
  for(int i=0;i<m;i++){
    long long v;
    cin >> v;
    auto it=sp.lower_bound({v,-1});
    it--;
    cout << (*it).second << ' ';
    cout << v-(*it).first << '\n';
  }
  return 0;
}