#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,q;
    cin >> n >> q;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    vector<pl> qv;
    for(long long i=0;i<q;i++){
      long long v;
      cin >> v;
      qv.push_back({v,i});
    }
    sort(qv.begin(),qv.end());
    reverse(qv.begin(),qv.end());
    vector<long long> res(q,-1);
    long long sug=0;
    for(int i=0;i<n;i++){
      sug+=a[i];
      while(!qv.empty()){
        if(qv.back().first>sug){break;}
        res[qv.back().second]=i+1;
        qv.pop_back();
      }
    }
    for(auto &nx : res){cout << nx << '\n';}
  }
  return 0;
}