#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<vector<pi>> mem(n);
  vector<int> res(n,0);
  for(int i=1;i<=m;i++){
    int l,r,d;
    cin >> l >> r >> d;
    l--;r--;
    for(int j=0;j<d;j++){
      mem[l].push_back({r-1,i});
    }
    res[r]=m+1;
  }
  priority_queue<pi,vector<pi>,greater<pi>> pq;
  for(int i=0;i<n;i++){
    for(auto &nx : mem[i]){pq.push(nx);}
    if(res[i]!=0){continue;}
    if(pq.empty()){continue;}
    pi od=pq.top();pq.pop();
    //cout << i << ':' << od.first << ' ' << od.second << '\n';
    if(od.first<i){cout << "-1\n";return 0;}
    res[i]=od.second;
  }
  if(!pq.empty()){cout << "-1\n";return 0;}
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}