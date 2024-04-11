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
    long long n,k,x;
    cin >> n >> k >> x;
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    vector<long long> res(n);
    vector<pl> pv;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      pv.push_back({v,i});
    }
    sort(pv.begin(),pv.end());
    reverse(pv.begin(),pv.end());
    for(int i=0;i<k;i++){pq.push({0,i+1});}
    cout << "YES\n";
    for(int i=0;i<n;i++){
      pl od=pq.top();pq.pop();
      od.first+=pv[i].first;
      res[pv[i].second]=od.second;
      pq.push(od);
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}