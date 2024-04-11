#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int f(int x){
  for(int i=0;;i++){
    if((1<<i)+2>x){
      return (1<<i)+2-x;
    }
  }
}

using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int,pair<pi,pi>> mp;
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    v++;
    pq.push(v);
    mp[v].first=make_pair(0,i+1);
  }
  while(!pq.empty()){
    int od=pq.top();pq.pop();
    if((!pq.empty()) && od==pq.top()){continue;}
    if(od!=1){
      int nx=f(od);
      pq.push(nx);
      pi send=mp[od].first;
      send.first++;
      if(mp[nx].first<send){
        mp[nx].second=mp[nx].first;
        mp[nx].first=send;
      }
      else if(mp[nx].second<send){mp[nx].second=send;}
    }
  }
  int ra=0,rb=0,rc=-1;
  for(auto &nx : mp){
    pair<pi,pi> tg=nx.second;
    // cerr << nx.first << ':';
    // cerr << tg.first.first << ',' << tg.first.second << ' ';
    // cerr << tg.second.first << ',' << tg.second.second << '\n';
    if(tg.first.second==0 || tg.second.second==0){continue;}
    if(rc<tg.first.first+tg.second.first){
      rc=tg.first.first+tg.second.first;
      ra=tg.first.second;
      rb=tg.second.second;
    }
  }
  cout << ra << ' ' << rb << ' ' << rc << '\n';
  return 0;
}

// https://csacademy.com/app/graph_editor/
// 1 2
// 1 3
// 1 5
// 2 4
// 1 9
// 2 8
// 3 7
// 4 6
// 1 17
// 2 16
// 3 15
// 4 14
// 5 13
// 6 12
// 7 11
// 8 10