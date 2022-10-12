#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    mp[v]++;
  }
  priority_queue<int> pq;
  for(auto &nx : mp){
    pq.push(nx.second);
  }
  int res=0;
  for(int i=0;i<(n+1)/2;i++){
    int od=pq.top();pq.pop();
    int del=min(2,od);
    res+=del;
    od-=del;
    pq.push(od);
  }
  cout << res << "\n";
  return 0;
}